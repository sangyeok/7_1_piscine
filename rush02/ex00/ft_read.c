/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:51:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 19:43:27 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_addchar(char *line, char character)
{
	int		len;
	char	*new_line;
	int		i;

	len = ft_strlen(line);
	new_line = malloc(sizeof(char) * (len + 2));
	if (!new_line)
		return (0);
	i = -1;
	while (line[++i])
		new_line[i] = line[i];
	new_line[i] = character;
	new_line[i + 1] = '\0';
	free(line);
	return (new_line);
}

int	ft_init_line(char **line)
{
	*line = malloc(sizeof(char));
	if (!(*line))
		return (0);
	(*line)[0] = '\0';
	return (1);
}

int	ft_process_lines(char buffer, char **line, \
		t_number **number, t_digits **digit)
{
	if (buffer != '\n')
	{
		*line = ft_addchar(*line, buffer);
		if (!*line)
			return (0);
	}
	else if (**line && ft_parse_line(*line, number, digit))
	{
		free(*line);
		if (!ft_init_line(line))
			return (0);
	}
	else if (**line)
	{
		free(*line);
		return (0);
	}
	return (1);
}

int	ft_get_line(int file, t_number **number, t_digits **digit)
{
	char	*line;
	char	buffer[1];

	if (!ft_init_line(&line))
		return (0);
	while (read(file, buffer, 1) == 1)
		if (!ft_process_lines(buffer[0], &line, number, digit))
			return (0);
	free(line);
	return (1);
}

int	ft_read(char *dict, t_number **number, t_digits **digit)
{
	int	file;

	file = open(dict, O_RDWR);
	if (file > 0)
	{
		if (!ft_get_line(file, number, digit))
		{
			close(file);
			return (-1);
		}
		close(file);
		return (1);
	}
	else
	{
		close(file);
		return (0);
	}
}
