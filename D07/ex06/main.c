#include <stdio.h>
#include "ft_convert_base.c"

int main()
{
    printf("%s\n", ft_convert_base("393583", "0123456789", "0123456789AB"));
    printf("%s\n", ft_convert_base("-455", "0123456789", "0123456789AB"));
    printf("%s\n", ft_convert_base("-393583", "0123456789", "0123456789AB"));
    printf("%s\n", ft_convert_base("455", "0123456789", "0123456789AB"));

	printf("%s\n", ft_convert_base("2352525", "0123456789", "0123456789AB"));
	printf("%s\n", ft_convert_base("14", "0123456789", "0123456789AB"));
	printf("%s\n", ft_convert_base("0", "0123456789", "0123456789AB"));
	printf("%s\n", ft_convert_base(".", "0123456789", "0123456789AB"));
	printf("%s\n", ft_convert_base("12", "", "01"));
}