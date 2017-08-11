#include <unistd.h>

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if(!(s1[i] == ' ' || s2[i] == ' '))
			if ((s1[i] - s2[i]) != 0)
				return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	char	str[100];
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < argc)
	{
		j = 0;
		k = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
			{
				str[k] = argv[i][j];
				k++;
			}
			j++;
		}
		str[k] = '\0';
		ft_strlowcase(str);
		if (!(ft_strcmp(str, "president")) || !(ft_strcmp(str, "attack")) || !(ft_strcmp(str, "powers")))
		{
			ft_putstr("Alert!!!\n");
			return (0);
		}
		i++;
	}
	return (0);
}