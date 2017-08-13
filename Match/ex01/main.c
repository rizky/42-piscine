#include <stdio.h>
#include "nmatch.c"

int	main(int argc, char **argv)
{
	if(argv[1] && argv[2])
		printf("%d\n", nmatch(argv[1], argv[2]));
	return (0);
}
