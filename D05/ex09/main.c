#include "ft_strlowcase.c"
#include <stdio.h>

int main()
{
	char a[] = "ABCDEF";
	char b[] = "abcdEf";
	char c[] = "01234A";
	char d[] = "";

	printf("%s\n", ft_strlowcase(a));
	printf("%s\n", ft_strlowcase(b));
	printf("%s\n", ft_strlowcase(c));
	printf("%s\n", ft_strlowcase(d));
	return (0);
}
