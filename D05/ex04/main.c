#include <stdio.h>
#include "ft_strncpy.c"
#include <string.h>
int main(void)
{
	char dest[10000] = "Hello World";
	char src[] = "afada";
	
	printf("%s\n", ft_strncpy(dest, src, 1000));

	char dest1[10000] = "Hello World";
	char src1[] = "afada";
	
	printf("%s\n", strncpy(dest1, src1, 1000));
	return (0);
}
