#include <stdlib.h>
char	*ft_create_str(char **tab, char *sep)
{
	int i;
	int j;
	int c_count;
	char *str;

	c_count = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			j++;
			c_count++;
		}
		i++;
	}
	j = 0;
	while (sep[j])
		j++;
	str = (char*)malloc(sizeof(*str) * (c_count + (i * j));
	return (str);
}
char	*ft_join(char **tab, char *sep)
{
	int i;
	int j;
	int c_count;
	char *str;
	
	str = ft_create_str(tab, sep);
	c_count = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			str[c_count] = tab[i][j];
			j++;
			c_count++;
		}
		if(tab[i + 1])
		{
			j = 0;
			while (sep[j])
			{
				str[c_count] = sep[i];
				c_count++;
				j++;
			}
		}
		i++;
	}
	return (str);
}