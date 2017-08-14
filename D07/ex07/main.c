#include <stdio.h>
#include "ft_split.c"

int main()
{
	char **strtab;
	int *tab;
	int i;
	int j;

	char *str = "hello \t    \n world \n   apa \n kabar  \n";
	strtab = ft_split(str, " \t\n");
	i = 0;
	while(strtab[i])
	{
		printf("%s, ", strtab[i]);
		i++;
	}
}
