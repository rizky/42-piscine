#include "ft_strcapitalize.c"
#include <stdio.h>

int main()
{
	char a[] = "salut, comment tu vas? 42mots quarante-deux; cinguante+et+un";

	printf("%s\n", ft_strcapitalize(a));
	return (0);
}
