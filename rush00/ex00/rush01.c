/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:25:18 by segan             #+#    #+#             */
/*   Updated: 2022/04/17 21:32:16 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	c;
	int	r;

	r = 1;
	while (r <= y && x > 0)
	{
		c = 1;
		while (c <= x)
		{
			if ((r == 1 && c == 1) || (r == y && c == x && c != 1 && r != 1))
				ft_putchar('/');
			else if ((r == y && c == 1) || (r == 1 && c == x))
				ft_putchar('\\');
			else if ((r != 1 && r != y) && (c != 1 && c != x))
				ft_putchar(' ');
			else
				ft_putchar('*');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}
