/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:43:44 by segan             #+#    #+#             */
/*   Updated: 2022/04/17 21:27:37 by sangyeon         ###   ########.fr       */
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
			if (row == 1 && (col == x || col == 1))
				ft_putchar('A');
			else if (row == y && (col == x || col == 1))
				ft_putchar('C');
			else if ((col < x && col > 1) && (row > 1 && row < y))
				ft_putchar(' ');
			else
				ft_putchar('B');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
