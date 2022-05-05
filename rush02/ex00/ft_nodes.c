/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 03:41:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 19:46:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_header.h"

t_number	*create_num_node(int key, char **value)
{
	t_number	*new_node;

	new_node = 0;
	new_node = (t_number *)malloc(sizeof(t_number));
	if (!new_node)
		return (0);
	new_node->key = key;
	new_node->value = *value;
	if (!new_node->value)
	{
		free(new_node);
		return (0);
	}
	new_node->next = 0;
	return (new_node);
}

t_digits	*create_digit_node(int key, char **value)
{
	t_digits	*new_node;

	new_node = 0;
	new_node = (t_digits *)malloc(sizeof(t_digits));
	if (!new_node)
		return (0);
	new_node->key = key;
	new_node->value = *value;
	if (!new_node->value)
	{
		free(new_node);
		return (0);
	}
	new_node->next = 0;
	return (new_node);
}

int	ft_push_num(t_number **number, int key, char **value)
{
	t_number	*new_node;

	new_node = create_num_node(key, value);
	if (!new_node)
		return (0);
	if (!(*number))
		*number = new_node;
	else
	{
		if (!check_exists_num(key, *number))
		{
			free(new_node);
			return (0);
		}
		new_node->next = *number;
		*number = new_node;
	}
	return (1);
}

int	ft_push_digit(t_digits **digit, int key, char **value)
{
	t_digits	*new_node;

	new_node = create_digit_node(key, value);
	if (!new_node)
		return (0);
	if (!(*digit))
		*digit = new_node;
	else
	{
		if (!check_exists_digit(key, *digit))
		{
			free(new_node);
			return (0);
		}
		new_node->next = *digit;
		*digit = new_node;
	}
	return (1);
}
