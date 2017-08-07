#include "ft_strupcase.c"
#include <stdio.h>

int main()
{
	char a[] = "abcdef";
	char b[] = "ABCDeF";
	char c[] = "01234a";
	char d[] = "";

	printf("%s\n", ft_strupcase(a));
	printf("%s\n", ft_strupcase(b));
	printf("%s\n", ft_strupcase(c));
	printf("%s\n", ft_strupcase(d));
	return (0);
}
