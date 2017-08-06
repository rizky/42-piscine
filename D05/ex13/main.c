#include "ft_str_is_lowercase.c"
#include <stdio.h>

int main()
{
	char a[] = "abcdefghijklmnopqrstuvwxyz";
	char b[] = "abcdefghijklmnopqrstuvwxyz0";
	char c[] = "";

	printf("%d\n", ft_str_is_lowercase(a));
	printf("%d\n", ft_str_is_lowercase(b));
	printf("%d\n", ft_str_is_lowercase(c));
	return (0);
}
