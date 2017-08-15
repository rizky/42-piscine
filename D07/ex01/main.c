#include <stdio.h>
#include "ft_range.c"

int main()
{
	int min = -5;
	int max = -5;
	int *tab = ft_range(min, max);
	int i;
	int len = max - min;

	printf("%p, ", tab);
	i = 0;
	while (i < len)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}
