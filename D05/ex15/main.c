#include "ft_str_is_printable.c"
#include <stdio.h>

int main()
{
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0";
	char c[] = "0123\x1F abc";

	printf("%d\n", ft_str_is_printable(a));
	printf("%d\n", ft_str_is_printable(b));
	printf("%d\n", ft_str_is_printable(c));
	return (0);
}
