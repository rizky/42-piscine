#include <stdio.h>
#include "ft_atoi_base.c"

int main()
{
    int i ;
    i = ft_atoi_base("-0110101010", "01");
	printf("%d\n", i);
}