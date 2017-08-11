#include <stdio.h>
#include "ft_unmatch.c"

int main()
{
	int tab[9] = {1, 1, 2, 4, 3, 4, 2, 3, 5};
	printf("%d", ft_unmatch(tab, 9));
	return (0);
}