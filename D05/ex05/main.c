#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_strstr.c"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
	exit(EXIT_FAILURE);
	}
	
	printf("%s\n", strstr(argv[1], argv[2]));
	printf("%s\n", ft_strstr(argv[1], argv[2
	]));
	return (0);
}
