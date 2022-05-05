/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:50:31 by sangyeon          #+#    #+#             */
/*   Updated: 2022/05/05 14:05:23 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base_l(char *str);
int	check_base_c(char c, char *base);
int	whitespace_s(char *str, int *pos);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	base_l;
	int	sign;
	int	base_c;

	i = 0;
	result = 0;
	base_l = check_base_l(base);
	if (base_l)
	{
		sign = whitespace_s(str, &i);
		base_c = check_base_c(str[i], base);
		while (base_c != -1)
		{
			result = result * base_l + base_c;
			i++;
			base_c = check_base_c(str[i], base);
		}
		return (result * sign);
	}
	return (0);
}

int	check_len(long nb, char *base_to)
{
	int	len;
	int	base_l;

	len = 0;
	base_l = check_base_l(base_to);
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= base_l;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(char *str, long nb, char *base, int len)
{
	int		base_len;

	base_len = check_base_l(base);
	str[len--] = '\0';
	if (nb == 0)
	{
		str[0] = base[0];
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[len] = base[nb % base_len];
		nb /= base_len;
		len--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	result;
	int		len;
	char	*str;

	if (!check_base_l(base_from) || !check_base_l(base_to))
		return (0);
	result = ft_atoi_base(nbr, base_from);
	len = check_len(result, base_to);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str = ft_itoa_base(str, result, base_to, len);
	return (str);
}
