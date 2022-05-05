/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:53:03 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/17 13:54:58 by sangyeon         ###   ########.fr       */
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
			if ((row == 1 || row == y) && (col == 1 || col == x))
				ft_putchar('o');
			else if ((row == 1 || row == y) && (col < x && col > 1))
				ft_putchar('-');
			else if ((col == 1 || col == x) && (row > 1 && row < y))
				ft_putchar('|');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
