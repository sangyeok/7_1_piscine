/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:44:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 16:51:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_header.h"

void	ft_num_swap(t_number *number)
{
	int		temp_key;
	char	*temp_value;

	temp_key = number->key;
	temp_value = number->value;
	number->key = number->next->key;
	number->value = number->next->value;
	number->next->key = temp_key;
	number->next->value = temp_value;
}

void	ft_digit_swap(t_digits *digit)
{
	int		temp_key;
	char	*temp_value;

	temp_key = digit->key;
	temp_value = digit->value;
	digit->key = digit->next->key;
	digit->value = digit->next->value;
	digit->next->key = temp_key;
	digit->next->value = temp_value;
}

void	ft_num_sort(t_number **number)
{
	t_number	*n1;
	t_number	*n2;

	n1 = *number;
	while (n1)
	{
		n2 = *number;
		while (n2->next)
		{
			if (n2->key < n2->next->key)
				ft_num_swap(n2);
			n2 = n2->next;
		}
		n1 = n1->next;
	}
}

void	ft_digit_sort(t_digits **digit)
{
	t_digits	*d1;
	t_digits	*d2;

	d1 = *digit;
	while (d1)
	{
		d2 = *digit;
		while (d2->next)
		{
			if (d2->key < d2->next->key)
				ft_digit_swap(d2);
			d2 = d2->next;
		}
		d1 = d1->next;
	}
}
