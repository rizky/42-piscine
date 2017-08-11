#include <stdio.h>
unsigned int ft_active_bits(int value);

int main(void)
{
	printf("%d\n", ft_active_bits(0));
	printf("%d\n", ft_active_bits(1));
	printf("%d\n", ft_active_bits(6));
	printf("%d\n", ft_active_bits(7));
	printf("%d\n", ft_active_bits(10));
	return (0);
}
