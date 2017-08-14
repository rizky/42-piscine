/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:23:57 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/14 11:16:42 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	wcount = wcount + 1;
	return (wcount);
}

int		*ft_lettercounter(char *str, char **strtab, int wcount)
{
	int		*tab;
	int		i;
	int		j;
	int		ccount;
	int		state;

	tab = (int*)malloc(sizeof(*tab) * (wcount));
	i = 0;
	j = 0;
	ccount = 0;
	state = 0;
	while (str[i])
	{
		if ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		{
			if (state == 1)
			{
				tab[j] = ccount;
				strtab[j] = (char*)malloc(sizeof(*strtab) * (ccount + 1));
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
	tab[j] = ccount;
	tab[j + 1] = 1;
	return (tab);
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
	while (str[i])
	{
		if ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
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
