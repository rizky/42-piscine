#include <stdio.h>
#include "ft_strdup.c"

int main(void)
{
	char str1[] = "Hello World";

	printf("%s", ft_strdup(str1));
	return (0);
}
