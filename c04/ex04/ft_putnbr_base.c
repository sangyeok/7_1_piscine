/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:21:59 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/26 16:02:04 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (str[0] == '\0' || len == 1)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		error;
	long	n;

	len = ft_strlen(base);
	error = check_base(base);
	n = nbr;
	if (error == 1)
	{
		if (n < 0)
		{
			write (1, "-", 1);
			n *= -1;
		}
		if (n >= len)
			ft_putnbr_base(n / len, base);
		ft_putchar(base[n % len]);
	}
}
