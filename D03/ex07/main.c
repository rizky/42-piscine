#include "ft_strrev.c"
#include <stdio.h>

int main()
{
    char str[]="12345";

    printf("%s\n", str);
    printf("%s\n", ft_strrev(str));

    char str1[]="a";

    printf("%s\n", str1);
    printf("%s\n", ft_strrev(str1));

    char str2[]="";

    printf("%s\n", str2);
    printf("%s\n", ft_strrev(str2));

    return (0);
}