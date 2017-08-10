#include <stdio.h>
#include "ft_split_whitespaces.c"

int main()
{
	char **strtab;
	int *tab;
	int i;
	int j;

	char *str = "hello \n \t world apa kabar";
/*	strtab = ft_split_whitespaces(str);
	i = 0;
	while(strtab[i][0] != '\0')
	{
		printf("%s, ", strtab[i]);
		i++;
		}*/
	i = 0;
	int wcount;
	wcount = ft_wordcounter(str);
	printf("\n%d\n", wcount);
	tab = ft_lettercounter(str, strtab,  wcount);
	while (i < wcount)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}
