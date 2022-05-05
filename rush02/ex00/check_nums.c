/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 03:15:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 19:59:57 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	find_node(int num, t_number *number, int *flag)
{
	if (*flag == 0)
		*flag = 1;
	else if (*flag == 1)
		ft_putchar(' ');
	while (number)
	{
		if (num == number->key)
			ft_putstr(number->value);
		number = number->next;
	}
}

void	print_num(int num, t_number *number, int *flag)
{
	if (num / 100)
	{
		find_node(num / 100, number, flag);
		find_node(100, number, flag);
		if (flag == 0 && num % 100 == 0)
			return ;
	}
	num -= (num / 100) * 100;
	if (num / 10)
	{
		if (num >= 10 && num < 20)
		{
			find_node(num, number, flag);
			return ;
		}
		else
			find_node(num - (num % 10), number, flag);
		if (flag == 0 && num % 10 == 0)
			return ;
	}
	num -= (num / 10) * 10;
	if (num)
		find_node(num, number, flag);
}

int	three_num(char *input, t_number *number, int len, int *flag)
{
	int		idx;
	int		num;
	char	str[4];

	idx = 0;
	while (idx < len)
	{
		str[idx] = input[idx];
		idx ++;
	}
	str[idx] = 0;
	num = atoi(str);
	print_num(num, number, flag);
	return (num);
}

void	print_digit(int num, t_digits *digit, int len)
{
	len++;
	if (!num)
		return ;
	ft_putchar(' ');
	while (digit)
	{
		if (len == digit->key)
			ft_putstr(digit->value);
		digit = digit->next;
	}
}

void	sep_num(char *input, t_number *number, t_digits *digit, int len_input)
{
	int	flag;
	int	num;

	flag = 0;
	if (is_zero(input, number, len_input, &flag))
		return ;
	while (*input && len_input >= 4)
	{
		if (len_input % 3 == 0)
		{
			num = three_num(input, number, 3, &flag);
			print_digit(num, digit, len_input - 3);
			input += 3;
			len_input -= 3;
		}
		else
		{
			num = three_num(input, number, len_input % 3, &flag);
			input += len_input % 3;
			print_digit(num, digit, len_input - (len_input % 3));
			len_input -= len_input % 3;
		}
	}
	three_num(input, number, len_input, &flag);
	ft_putchar('\n');
}
