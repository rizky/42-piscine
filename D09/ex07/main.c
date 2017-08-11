#include <stdio.h>

unsigned int ft_collatz_conjecture(unsigned int base);
int main()
{
	printf("%d\n", ft_collatz_conjecture(1));
	printf("%d\n", ft_collatz_conjecture(2));
	printf("%d\n", ft_collatz_conjecture(3));
	printf("%d\n", ft_collatz_conjecture(4));
	printf("%d\n", ft_collatz_conjecture(5));
	printf("%d\n", ft_collatz_conjecture(6));
	printf("%d\n", ft_collatz_conjecture(1024));
    return (0);
}