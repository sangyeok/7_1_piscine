/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:30:37 by sangyeon          #+#    #+#             */
/*   Updated: 2022/05/02 10:18:49 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_pri(int nb)
{
	int	i;

	i = 2;
	if (nb < 2 || nb == 4)
		return (0);
	if (nb == 2)
		return (1);
	while ((i < nb / 2) && i < 46341)
	{
		if ((nb % i) != 0)
			i++;
		else if ((nb % i) == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_pri(nb) == 1)
		return (nb);
	else
	{
		while (ft_is_pri(nb) == 0)
			nb++;
		return (nb);
	}
	return (0);
}
