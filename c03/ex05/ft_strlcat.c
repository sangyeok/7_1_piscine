/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:18:21 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/26 15:56:46 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned	int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	j = dlen;
	if (size <= dlen)
		return (slen + size);
	while (src[i] && i < size - dlen - 1)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dlen + slen);
}
