#include <stdio.h>
#include "ft_short_integer_table.c"

int main()
{
    int tab[9] = { 1, 4, 3, 2, 1, 0, 11, 29, 1 };
    int *ptr;
	int i;
	int size;

	size = 9;
	ft_sort_integer_table(tab, size);

	ptr = tab;
	i = 0;
	while (i < size)
	{
		printf("%d, ", *ptr);
		ptr++;
		i++;
	}
    return (0);
}