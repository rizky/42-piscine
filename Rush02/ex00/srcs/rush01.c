#include "ft.h"

char *base;

void	ft_get_line01(int x, char a, char b, char c)
{
	int i;
	
	if (x == 1)
		base = ft_strcatch(base, a);
	if (x > 1)
	{
		i = 2; 
		base = ft_strcatch(base, a);
		while (i < x)
		{
			base = ft_strcatch(base, b);
			i++;
		}
		base = ft_strcatch(base, c);
	}
	base = ft_strcatch(base, '\n');
}

char	*rush01(int x, int y, int len)
{
	int i;
	
	base = (char*)malloc(sizeof(char) * (len + 1));
	if (y == 1)
	ft_get_line01(x, '/', '*', '\\');
	if (y > 1)
	{
		i = 2;
		ft_get_line01(x, '/', '*', '\\');
		while (i < y)
		{
			ft_get_line01(x, '*', ' ', '*');
			i++;
		}
		ft_get_line01(x, '\\', '*', '/');
	}
	return (base);
}