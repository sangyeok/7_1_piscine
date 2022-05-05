/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:09:37 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/24 13:44:19 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)

{
	int	i;
	int	tem;

	i = 0;
	while (i < size - 1)
	{
		tem = tab[size - 1];
		tab[size - 1] = tab[i];
		tab[i] = tem;
		i++;
		size--;
	}
}
