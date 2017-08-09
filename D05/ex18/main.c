#include <stdio.h>
#include "ft_strlcat.c"
#include <string.h>

int main(void)
{
	char a[34] = "";
	char b[] = "this 6\0";
	printf("%lu\n",strlcat(a,b,10));
	printf("%s\n",a);
	char d[34] = "this 6";
	char e[] = "";
	printf("%lu\n",strlcat(d,e,5));
	printf("%s\n",d);
	printf("-------------------\n");
	char f[34] = "";
	char g[] = "this 6\0";
	printf("%d\n",ft_strlcat(f,g,10));
	printf("%s\n",f);
	char h[34] = "this 6\0";
	char i[] = "";
	printf("%d\n",ft_strlcat(h,i,5));
	printf("%s\n",h);



	return (0);
}
