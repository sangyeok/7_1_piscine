/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:26:47 by sangyeon          #+#    #+#             */
/*   Updated: 2022/04/26 16:03:11 by sangyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_base_l(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
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
	return (i);
}

int	check_base_c(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	whitespace_s(char *str, int *pos)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*pos = i;
	return (sign);
}

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

/*#include <stdio.h>
int main()
{
	printf("------ ex05 ------\n\n");
	char ex05_str1[] = " \n -+-++-+2147483648";
	char ex05_str2[] = "   ---+AABCDESSEZ";
	char ex05_str3[] = "   ++136667";
	char ex05_str4[] = "   -----+-+!!@@#..<";
	char ex05_str5[] = "  \n \tatoi12-+123base";
	printf("-2147483648\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, "0123456789"));
	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, ""));
	printf("-67174\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, "ABCDES"));
	printf("-1\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, "ABZ"));
	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "A-+"));
	printf("12347\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "3405816"));
	printf("1126397\n");
	printf("%d\n\n", ft_atoi_base(ex05_str4, "!@#$%^&*()~?><'."));
	printf("27\n");
	printf("%d\n\n", ft_atoi_base(ex05_str5, "atoi"));
}*/
