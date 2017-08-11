#include <stdio.h>
#include "ft_button.c"

int ft_button(int i, int j, int k);

int main(void)
{
	printf("%d\n", ft_button(1, 2, 3));
	printf("%d\n", ft_button(2, 1, 3));
	printf("%d\n", ft_button(3, 1, 2));
	printf("%d\n", ft_button(3, 2, 1));
	printf("%d\n", ft_button(3, 3, 3));
	printf("%d\n", ft_button(3, 2, 3));
	printf("%d\n", ft_button(-1, -2, -3));
	printf("%d\n", ft_button(10, 2, 30));
	return (0);
}
