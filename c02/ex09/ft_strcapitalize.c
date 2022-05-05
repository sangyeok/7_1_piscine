/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:27:16 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/25 09:52:46 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	lowercase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

void	uppercase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
			lowercase(&str[i]);
		else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			lowercase(&str[i]);
		else if (str[i - 1] >= '0' && str[i - 1] <= '9')
			lowercase(&str[i]);
		else
			uppercase(&str[i]);
		i++;
	}
	return (str);
}
