/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:23:35 by sangyeon          #+#    #+#             */
/*   Updated: 2022/05/04 16:49:57 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_double(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	check_word(char *str, char *sep)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	if (check_double(str[0], sep) == 1)
		cnt++;
	while (str[i])
	{
		if ((check_double(str[i - 1], sep) == 0)
			&& (check_double(str[i], sep) == 1))
		{
			cnt++;
			i++;
		}
		else
			i++;
	}
	return (cnt);
}

int	ft_valid_word(char *str, char *sep)
{
	int	i;

	i = 0;
	while ((check_double(str[i], sep) == 1) && str[i])
		i++;
	return (i);
}

char	*tab_word(char *str, char *sep)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = ft_valid_word(str, sep);
	word = malloc(sizeof(char) * len);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		len;
	char	**tab;
	int		i;

	i = 0;
	len = check_word(str, charset);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (0);
	while (*str)
	{
		while ((check_double(*str, charset) == 0) && *str)
			str++;
		if (*str)
		{
			tab[i] = tab_word(str, charset);
			i++;
		}
		while ((check_double(*str, charset) == 1) && *str)
			str++;
	}
	tab[i] = 0;
	return (tab);
}
