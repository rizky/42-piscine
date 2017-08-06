#include <stdio.h>
#include "ft_strncat.c"
#include <string.h>

int main(void)
{
	char a[34] = "first part of string";
	char b[] = "second part";
	printf("%s\n",strncat(a,b,3));
	char d[34] = "first part of string";
	char e[] = "second part";
	printf("%s\n",strncat(d,e,10));

	char a1[34] = "first part of string";
	char b1[] = "second part";
	printf("%s\n",strncat(a1,b1,3));
	char d1[34] = "first part of string";
	char e1[] = "second part";
	printf("%s\n",strncat(d1,e1,10));

	return (0);
}
