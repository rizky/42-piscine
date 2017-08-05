#include "ft_find_next_prime.c"

int main()
{
	printf("%d\n",ft_find_next_prime(-42));
	printf("%d\n",ft_find_next_prime(0));
	printf("%d\n",ft_find_next_prime(1));
	printf("%d\n",ft_find_next_prime(2));
	printf("%d\n",ft_find_next_prime(3));
	printf("4 - %d\n",ft_find_next_prime(4));
	printf("%d\n",ft_find_next_prime(17));
	printf("104729 - %d\n",ft_find_next_prime(104729));
	printf("104743 - %d\n",ft_find_next_prime(104743));
	printf("%d\n",ft_find_next_prime(146));
	printf("147 -%d\n",ft_find_next_prime(147));
	printf("%d\n",ft_find_next_prime(148));
	printf("149 - %d\n",ft_find_next_prime(149));
	printf("%d\n",ft_find_next_prime(288));
	printf("%d\n",ft_find_next_prime(361));
	printf("%d\n",ft_find_next_prime(529));
	printf("%d\n",ft_find_next_prime(960));
}
