/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:33:55 by sangyeon          #+#    #+#             */
/*   Updated: 2022/05/04 20:40:41 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*tab;

	i = 0;
	len = ft_strlen(src);
	tab = malloc(len + 1);
	if (!tab)
		return (0);
	while (src[i])
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tmp;
	int			i;

	tmp = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < ac)
	{
		tmp[i].size = ft_strlen(av[i]);
		tmp[i].str = av[i];
		tmp[i].copy = ft_strdup(av[i]);
		i++;
	}
	tmp[i].str = 0;
	return (tmp);
}
