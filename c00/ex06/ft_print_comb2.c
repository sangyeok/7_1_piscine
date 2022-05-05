/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:00:07 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/16 15:04:21 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			putchar(x / 10 + 48);
			putchar(x % 10 + 48);
			write(1, " ", 1);
			putchar(y / 10 + 48);
			putchar(y % 10 + 48);
			if (x != 98)
				write(1, ", ", 2);
			y++;
		}
		x++;
	}
}
