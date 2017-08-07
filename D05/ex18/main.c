#include <stdio.h>
#include "ft_strlcat.c"
#include <string.h>

int main(void)
{
	char a[34] = "this is 10\0";
	char b[] = "this 6\0";
	printf("%lu\n",strlcat(a,b,12));
	printf("%s\n",a);
	// char d[34] = "this 6\0";
	// char e[] = "this is 10\0";
	// printf("%lu\n",strlcat(d,e,5));
	// printf("%s\n",d);
	printf("-------------------\n");
	char f[34] = "this is 10\0";
	char g[] = "this 6\0";
	printf("%d\n",ft_strlcat(f,g,12));
	printf("%s\n",f);
	// char h[34] = "this 6\0";
	// char i[] = "this is 10\0";
	// printf("%d\n",ft_strlcat(h,i,5));
	// printf("%s\n",i);



	return (0);
}
