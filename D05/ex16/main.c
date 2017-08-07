#include <stdio.h>
#include "ft_strcat.c"
#include <string.h>

int main(void)
{
	char a[34] = "first part of string";
	char b[] = "second part";
//	printf("%s\n",strcat(a,b));
	printf("%s\n",ft_strcat(a,b));

	return (0);
}
