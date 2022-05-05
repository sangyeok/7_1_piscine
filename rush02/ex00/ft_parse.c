/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:11:13 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 20:58:18 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	is_valid_dict(char *line)
{
	char	*temp;
	int		count;

	temp = line;
	count = 0;
	while (*temp >= '0' && *temp <= '9')
		temp++;
	if ((temp - line) == 0)
		return (0);
	while (ft_isspace(*temp))
		temp++;
	if (*temp != ':')
		return (0);
	while (ft_isspace(*temp))
		temp++;
	line = temp;
	while (*temp)
	{
		if (ft_isprintable(*temp))
			count++;
		temp++;
	}
	if (!count || (count != (temp - line)))
		return (0);
	return (1);
}

int	ft_get_num_len(char *line)
{
	char	*temp;

	temp = line;
	while (*temp >= '0' && *temp <= '9')
		temp++;
	return (temp - line);
}

void	ft_store(char *line, char **num, char **value)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	*num = ft_strndup(line, i + 1);
	while (ft_isspace(line[i]))
		i++;
	i++;
	while (ft_isspace(line[i]))
		i++;
	j = 0;
	while (ft_isprintable(line[i]))
	{
		i++;
		j++;
	}
	*value = ft_strndup(line + i - j, j + 1);
}

int	ft_parse_line(char *line, t_number **number, t_digits **digit)
{
	int		key_digit;
	int		key_num;
	char	*num;
	char	*value;

	if (!is_valid_dict(line))
		return (0);
	key_digit = ft_get_num_len(line);
	ft_store(line, &num, &value);
	if (!(*num) || !(*value))
		return (0);
	if (key_digit > 3)
	{
		free(num);
		if (!check_digit(key_digit, digit, value))
			return (0);
	}
	else
	{
		key_num = ft_atoi(num);
		free(num);
		if (!check_num(key_num, number, value))
			return (0);
	}
	return (1);
}
