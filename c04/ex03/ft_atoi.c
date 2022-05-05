/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:02:47 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/26 15:50:12 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*int main()
{
	printf("------ ex03 ------\n");
	char ex03_str1[] ="\t   ----++000846545ags56";
	char ex03_str2[] = "  	 \t	-+--1165ataat++-156";
	char ex03_str3[] = "214564564512313546";
	printf("str1 : %s\nft_atoi(str1) = %d\n\n", ex03_str1, ft_atoi(ex03_str1));
	printf("str2 : %s\nft_atoi(str2) = %d\n\n", ex03_str2, ft_atoi(ex03_str2));
	printf("str3 : %s\nft_atoi(str3) = %d\n\n", ex03_str3, ft_atoi(ex03_str3));
}*/
