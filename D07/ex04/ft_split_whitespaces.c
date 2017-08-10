/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:23:57 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/10 18:57:04 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

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
				ccount = 0;
				strtab[j] = (char*)malloc(sizeof(*strtab) * (ccount + 1));
				j++;
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

char	**ft_split_whitespaces(char *str)
{
	char	**strtab;
	int		*tab;
	int		wcount;

	wcount = ft_wordcounter(str);
	strtab = (char**)malloc(sizeof(*strtab) * (wcount + 1));
	tab = ft_lettercounter(str, strtab, wcount);
	
	strtab[wcount] = (char*)malloc(sizeof(*strtab) * (1));
	strcpy(strtab[wcount], "");
	return (strtab);
}
