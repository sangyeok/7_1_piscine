#include <unistd.h>

void	ltwd(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	while (i > 0)
	{
		if(str[i] == 32 || str[i] == '\t')
			break;
		i--;
	}
	i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		ltwd(av[1]);
	write(1, "\n", 1);
	return (0);
}
