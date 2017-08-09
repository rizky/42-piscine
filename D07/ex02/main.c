#include <stdio.h>
#include "ft_ultimate_range.c"

int main()
{
	int min = -5;
	int max = 10;
	int *tab;
	int i;
	int len = max - min;

	printf("%d\n", ft_ultimate_range(&tab, min, max));

	i = 0;
	while (i < len)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}
