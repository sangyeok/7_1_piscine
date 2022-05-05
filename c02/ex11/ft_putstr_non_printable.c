/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:59:11 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/24 16:54:58 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			write (1, "\\", 1);
			write (1, &hex[(unsigned char)str[i] / 16], 1);
			write (1, &hex[(unsigned char)str[i] % 16], 1);
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}
