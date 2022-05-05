/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:37:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 20:01:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_header.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_isprintable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

char	*ft_strndup(char *str, int size)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);
	while (*str && i < (size - 1))
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(char *str)
{
	int		size;
	int		i;
	char	*dup;

	i = 0;
	size = ft_strlen(str) + 1;
	dup = (char *)malloc(sizeof(char) * size);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
