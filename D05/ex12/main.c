#include "ft_str_is_numeric.c"
#include <stdio.h>

int main()
{
	char a[] = "0123456789";
	char b[] = "0123456789a";
	char c[] = "";

	printf("%d\n", ft_str_is_numeric(a));
	printf("%d\n", ft_str_is_numeric(b));
	printf("%d\n", ft_str_is_numeric(c));
	return (0);
}
