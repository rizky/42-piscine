#include <stdio.h>
#include "ft_strlcat.c"
#include <string.h>

int main(void)
{
	char a[] = "this is 10\0";
	char b[] = "this 6\0";
	printf("%lu\n",strlcat(a,b,10));
	char d[] = "this 6\0";
	char e[] = "this is 10\0";
	printf("%lu\n",strlcat(d,e,5));

	char a1[] = "this is 10\0";
	char b1[] = "this 6\0";
	printf("%u\n",ft_strlcat(a1,b1,10));
	char d1[] = "this 6\0";
	char e1[] = "this is 10\0";
	printf("%u\n",ft_strlcat(d1,e1,5));
	return (0);
}
