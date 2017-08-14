#include <stdio.h>
#include "ft_convert_base.c"

int main()
{
    printf("%s\n", ft_convert_base("1101111", "01", "0123456789ABCDEF"));
}