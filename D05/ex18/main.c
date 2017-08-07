#include <stdio.h>
#include "ft_strlcat.c"
#include <string.h>

int main(void)
{
	char a[34] = "this is 10\0";
	char b[] = "this 6\0";
	printf("%d\n",strlcat(a,b,10));
	char d[34] = "this 6\0";
	char e[] = "this is 10\0";
	printf("%d\n",strlcat(d,e,5));

	char a1[34] = "first part of string";
	char b1[] = "second part";
	printf("%d\n",ft_strlcat(a1,b1,3));
	char d1[34] = "first part of string";
	char e1[] = "second part";
	printf("%d\n",ft_strlcat(d1,e1,10));

	return (0);
}
