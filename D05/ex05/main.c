#include <stdio.h>
#include "ft_strstr.c"

int main(void)
{
	char str[] = "this is a haystack";
	char to_find[] = " ";
	char *ptr;
	
	ptr = ft_strstr(str, to_find);
	printf("%s\n", ptr);
	return (0);
}
