#include <stdio.h>
#include "match.c"

int	main(int argc, char **argv)
{
	if(argv[1] && argv[2])
		printf("%d\n", match(argv[1], argv[2]));
	return (0);
}
