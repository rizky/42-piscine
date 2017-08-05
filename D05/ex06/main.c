#include <stdio.h>
//#include "ft_strcmp.c"

int main(void)
{
	printf("%d\n",strcmp("string1","string2"));
	printf("%d\n",strcmp("","\tstring2"));
	printf("%d\n",strcmp("",""));
	printf("%d\n",strcmp("ABCDEF","ABCDF"));

	return (0);
}
