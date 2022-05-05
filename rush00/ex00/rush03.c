/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:54:13 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/17 13:57:06 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 1;
	while (row <= y && x > 0)
	{
		col = 1;
		while (col <= x)
		{
			if (col == 1 && (row == 1 || row == y))
				ft_putchar('A');
			else if (col == x && (row == 1 || row == y))
				ft_putchar('C');
			else if (row > 1 && row < y && col > 1 && col < x)
				ft_putchar(' ');
			else
				ft_putchar('B');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
