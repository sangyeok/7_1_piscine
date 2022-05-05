/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ready.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:25:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 21:25:44 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	init_all(char **input, char **dict, t_number **number, t_digits **digit)
{
	*input = 0;
	*dict = 0;
	*number = 0;
	*digit = 0;
}

int	check_dict(int argc, char **argv, char **input, char **dict)
{
	if (argc == 2)
	{
		*dict = ft_strdup("numbers.dict");
		if (!*dict)
			return (0);
		*input = ft_strdup(argv[1]);
		if (!*input)
			return (0);
		return (1);
	}
	else if (argc == 3)
	{
		*dict = ft_strdup(argv[1]);
		if (!*dict)
			return (0);
		*input = ft_strdup(argv[2]);
		if (!*input)
			return (0);
		return (1);
	}
	else
		return (0);
}

int	check_input_part2(char **input, char *temp, int count, int check)
{
	if (count)
	{
		free(*input);
		*input = ft_strndup(temp - count, count + 1);
		if (!*input)
			return (0);
		return (1);
	}
	else if (check)
	{
		free(*input);
		*input = malloc(sizeof(char) * 2);
		if (!*input)
			return (0);
		(*input)[0] = '0';
		(*input)[1] = 0;
		return (1);
	}
	else
	{
		free(*input);
		return (0);
	}
}

int	check_input_part1(char **input, int check)
{
	char	*temp;
	int		count;

	temp = *input;
	count = 0;
	while (ft_isspace(*temp))
		temp++;
	if (*temp == '+')
		temp++;
	while (*temp == '0')
	{
		check = 1;
		temp++;
	}
	while (*temp)
	{
		if (!(*temp >= '0' && *temp <= '9'))
			return (0);
		count++;
		temp++;
	}
	if (!check_input_part2(input, temp, count, check))
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	len;
	int	idx;
	int	value;

	len = ft_strlen(str);
	idx = 0;
	value = 0;
	while (idx < len)
	{
		value *= 10;
		value += str[idx] - '0';
		idx ++;
	}
	return (value);
}
