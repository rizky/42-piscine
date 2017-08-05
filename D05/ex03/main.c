#include <stdio.h>
#include "ft_strcpy.c"

int main(void)
{
	char dest[] = "Hello World";
	char src[] = "Hey";
	
	printf("%s", ft_strcpy(dest, src));
	return (0);
}
