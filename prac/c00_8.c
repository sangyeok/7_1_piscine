/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c00_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:53:47 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/19 17:55:57 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_dfs(int n, char *check, int start, int depth)
{
	int	j;

	j = start;
	if (depth == n)
	{
		write(1, check, n);
		if (check[0] != 10 - n + '0')
			write(1, ", ", 2);
	}
	else
	{
		while (j < 10)
		{
			check[depth] = j + '0';
			ft_dfs(n, check, j + 1, depth + 1);
			j++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	visited[9];	

	ft_dfs(n, visited, 0, 0);
}
