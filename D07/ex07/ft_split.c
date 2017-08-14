#include <stdlib.h>

char	*ft_strstr(char *str, char to_find)
{
	int i;
	int j;

	if (to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			{
				return (str+i);
			}
		i++;
	}
	return (NULL);
}

int		ft_wordcounter(char *str, char *sep)
{
	int		i;
	int		wcount;
	int		state;

	i = 0;
	wcount = 0;
	state = 0;
	while (str[i])
	{
		if (ft_strstr(sep,str[i]) != NULL)
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

char	**ft_word_extractor(char *str, char **strtab, int wcount, char *sep)
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
		if (ft_strstr(sep,str[i]) != NULL)
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

char	**ft_split(char *str, char *charset)
{
	char	**strtab;
	int		*tab;
	int		wcount;
	int		i;
	int		j;

	wcount = ft_wordcounter(str, charset);
	strtab = (char**)malloc(sizeof(*strtab) * (wcount + 1));

	strtab = ft_word_extractor(str, strtab, wcount, charset);
	return (strtab);
}