#include "ft_str_is_uppercase.c"
#include <stdio.h>

int main()
{
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0";
	char c[] = "";

	printf("%d\n", ft_str_is_uppercase(a));
	printf("%d\n", ft_str_is_uppercase(b));
	printf("%d\n", ft_str_is_uppercase(c));
	return (0);
}
