#include <stdio.h>
#include "ft_strcmp.c"
#include <string.h>

int main(void)
{
	printf("%d\n",strcmp("string1","string2"));
	printf("%d\n",strcmp("","\tstring2"));
	printf("%d\n",strcmp("",""));
	printf("%d\n",strcmp("ABCDEF","ABCDE"));
	printf("----\n");
	printf("%d\n",ft_strcmp("string1","string2"));
	printf("%d\n",ft_strcmp("","\tstring2"));
	printf("%d\n",ft_strcmp("",""));
	printf("%d\n",ft_strcmp("ABCDEF","ABCDE"));

	return (0);
}
