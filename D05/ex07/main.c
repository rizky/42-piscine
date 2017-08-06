#include <stdio.h>
#include "ft_strncmp.c"
#include <string.h>

int main(void)
{
	printf("%d\n",strncmp("string1","string2",0));
	printf("%d\n",strncmp("","\tstring2",20));
	printf("%d\n",strncmp("","",2));
	printf("%d\n",strncmp("ABCDEF","ABCDE",2));
	printf("----\n");
	printf("%d\n",ft_strncmp("string1","string2",0));
	printf("%d\n",ft_strncmp("","\tstring2",20));
	printf("%d\n",ft_strncmp("","",2));
	printf("%d\n",ft_strncmp("ABCDEF","ABCDE",2));

	return (0);
}
