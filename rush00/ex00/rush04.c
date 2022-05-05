/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:54:43 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/17 14:03:03 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	r;
	int	c;

	r = 1;
	while (r <= y && x > 0)
	{
		c = 1;
		while (c <= x)
		{
			if ((r == 1 && c == 1) || (r == y && c == x && c != 1 && r != 1))
				ft_putchar('A');
			else if ((r == y && c == 1) || (r == 1 && c == x))
				ft_putchar('C');
			else if ((r != 1 && r != y) && (c != 1 && c != x))
				ft_putchar(' ');
			else
				ft_putchar('B');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}
