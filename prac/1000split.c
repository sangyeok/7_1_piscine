#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str)
{
	int i;
	int i2;
	int i3;
	char **tab;

	i = 0;
	i2 = 0;
	tab = (char**)malloc(sizeof(char*) * 1000);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			i3 = 0;
			tab[i2] = (char*)malloc(sizeof(char) * 1000);
			while (str[i] > 32)
			{
				tab[i2][i3] = str[i];
				i++;
				i3++;
			}
			tab[i2][i3] = '\0';
			i2++;
		}
		else
			i++;
	}
	tab[i2] = 0;
	return (tab);
}

int	main()
{
	int		index;
	char	**split;
	split = ft_split("_hello $my$##cool = frie nd !+");
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
}
