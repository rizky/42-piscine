#include <stdio.h>
#include "ft_split_whitespaces.c"

int main()
{
	char **strtab;
	int *tab;
	int i;
	int j;

	char *str = "hello \t    \n world \n   apa \n kabar  \n";
	strtab = ft_split_whitespaces(str);
	i = 0;
	while(strtab[i])
	{
		printf("%s, ", strtab[i]);
		i++;
	}
	i = 0;
	int wcount;
	wcount = ft_wordcounter(str);
	printf("\n%d\n", wcount);
}
