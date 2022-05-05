/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:21:37 by sangyeon          #+#    #+#             */
/*   Updated: 2022/05/04 16:34:07 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*tab;
	long	size;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	tab = *range;
	if (min < max)
	{
		while (i + min < max)
		{
			tab[i] = min + i;
			i++;
		}
	}
	return (max - min);
}
