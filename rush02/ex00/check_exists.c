/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 03:16:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 20:02:56 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_header.h"

int	check_exists_num(int key, t_number *number)
{
	while (number)
	{
		if (key == number->key)
			return (0);
		number = number->next;
	}
	return (1);
}

int	check_exists_digit(int key, t_digits *digit)
{
	while (digit)
	{
		if (key == digit->key)
			return (0);
		digit = digit->next;
	}
	return (1);
}

int	is_zero(char *input, t_number *number, int len_input, int *flag)
{
	if (len_input == 1 && input[0] == '0')
	{
		find_node(0, number, flag);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

int	check_digit(int key_digit, t_digits **digit, char *value)
{
	if (!check_exists_digit(key_digit, *digit))
		return (0);
	if (!ft_push_digit(digit, key_digit, &value))
		return (0);
	return (1);
}

int	check_num(int key_num, t_number **number, char *value)
{
	if (!check_exists_num(key_num, *number))
		return (0);
	if (!ft_push_num(number, key_num, &value))
		return (0);
	return (1);
}
