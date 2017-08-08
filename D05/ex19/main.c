#include <stdio.h>
#include "ft_strlcpy.c"
#include <string.h>

int main(void)
{
	char a[] = "this is 10";
	char b[] = "this 6";
	printf("%lu\n",strlcpy(a,b,1));
	printf("%s\n", a);
	char d[10] = "this 6";
	char e[] = "this is 10";
	printf("%lu\n",strlcpy(d,e,10));
	printf("%s\n", d);
	char f[15] = "this 6";
	char g[] = "this is 10";
	printf("%lu\n",strlcpy(f,g,15));
	printf("%s\n", f);
	char h[99] = "this 6\0";
	char i[] = "this is 10";
	printf("%lu\n",strlcpy(h,i,99));
	printf("%s\n", h);

	char a1[] = "this is 10";
	char b1[] = "this 6";
	printf("%u\n",ft_strlcpy(a1,b1,1));
	printf("%s\n", a);
	char d1[] = "this 6";
	char e1[] = "this is 10";
	printf("%u\n",ft_strlcpy(d1,e1,10));
	printf("%s\n", d);
	char f1[] = "this 6";
	char g1[] = "this is 10";
	printf("%u\n",ft_strlcpy(f1,g1,15));
	printf("%s\n", f);
	char h1[] = "this 6\0";
	char i1[] = "this is 10";
	printf("%u\n",ft_strlcpy(h1,i1,99));
	printf("%s\n", h);
	return (0);
}
