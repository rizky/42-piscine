#include <stdio.h>
#include "ft_strlcpy.c"
#include <string.h>

int main(void)
{
	char a[500] = "this is 10";
	char b[] = "this 6";
	printf("%lu\n",strlcpy(a,b,2));
	printf("%s\n", a);


	char a1[500] = "this is 10";
	char b1[] = "this 6";
	printf("%u\n",ft_strlcpy(a1,b1,2));
	printf("%s\n", a);
	return (0);
}
