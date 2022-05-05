/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:17:02 by sangyeon          #+#    #+#             */
/*   Updated: 2022/05/04 16:36:10 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	int		*tab;
	long	size;

	i = 0;
	size = max - min;
	if (min >= max)
		return (0);
	tab = malloc(sizeof(int) * size);
	if (min < max)
	{
		while (i + min < max)
		{
			tab[i] = min + i;
			i++;
		}
	}
	return (tab);
}
