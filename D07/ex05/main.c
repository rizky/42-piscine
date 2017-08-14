#include "ft_print_words_tables.c"

#include <stdlib.h>

int		ft_wordcounter(char *str)
{
	int		i;
	int		wcount;
	int		state;

	i = 0;
	wcount = 0;
	state = 0;
	while (str[i])
	{
		if ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		{
			state = 0;
		}
		else if (state == 0)
		{
			state = 1;
			wcount++;
		}
		i++;
	}
	return (wcount);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_word_extractor(char *str, char **strtab, int wcount)
{
	int		i;
	int		j;
	int		k;
	int		ccount;
	int		state;

	i = 0;
	j = 0;
	ccount = 0;
	state = 0;
	while (i <= ft_strlen(str))
	{
		if ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || (str[i] == '\0'))
		{
			if (state == 1)
			{
				strtab[j] = (char*)malloc(sizeof(*strtab) * (ccount + 1));
				k = 0;
				while (k < ccount)
				{
					strtab[j][k] = str[i - ccount + k];
					k++;
				}
				strtab[j][k] = '\0';
				j++;
				ccount = 0;
				state = 0;
			}
		}
		else if (state == 0)
		{
			state = 1;
			ccount++;
		}
		else
			ccount++;
		i++;
	}
	strtab[wcount] = NULL;
	return (strtab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**strtab;
	int		*tab;
	int		wcount;
	int		i;
	int		j;

	wcount = ft_wordcounter(str);
	strtab = (char**)malloc(sizeof(*strtab) * (wcount + 1));

	strtab = ft_word_extractor(str, strtab, wcount);
	return (strtab);
}

int main()
{
	char **strtab;
	char *str = "hello \t    \n world \n   apa \n kabar  \n";
	strtab = ft_split_whitespaces(str);

	ft_print_words_tables(strtab);
}