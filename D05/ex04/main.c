#include <stdio.h>
#include "ft_strncpy.c"

int main(void)
{
	char dest[] = "Hello World";
	char src[] = "Hey";
	
	printf("%s", ft_strncpy(dest, src, 11));
	return (0);
}
