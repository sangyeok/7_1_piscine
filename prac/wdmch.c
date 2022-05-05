#include <unistd.h>

int	ft_len(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void putst(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
void	ft_wdmatch(char *str, char *str1)
{
	int cnt;
	int i;
	int j;

	i = 0;
	j = 0;
	cnt = 0;
	while (str[i])
	{
		while (str1[j])
		{
			if (str[i] == str1[j])
			{
				cnt++;
				i++;
				break ;
			}
			j++;
		}
		if (str1[j] == '\0')
			break;
	}
	if (ft_len(str) == cnt)
		putst(str);
}
int	main(int ac, char **av)
{
	if (ac == 3)
		ft_wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
