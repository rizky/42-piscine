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

char	*ft_strcpy(int ccount, char *str, int i)
{
	char	*res;
	int		k;

	res = (char*)malloc(sizeof(char) * (ccount + 1));
	k = 0;
	while (k < ccount)
	{
		res[k] = str[i - ccount + k];
		k++;
	}
	res[k] = '\0';
	ccount = 0;
	return (res);
}

char	**ft_word_extractor(char *str, char **strtab, int wcount, int v[4])
{
	while (v[0] <= ft_strlen(str))
	{
		if ((str[v[0]] == ' ') || (str[v[0]] == '\t') || (str[v[0]] == '\n'))
		{
			if (v[3] == 1)
			{
				strtab[v[1]] = ft_strcpy(v[2], str, v[0]);
				v[1]++;
				v[2] = 0;
				v[3] = 0;
			}
		}
		else if (v[3] == 0)
		{
			v[3] = 1;
			v[2]++;
		}
		else
			v[2]++;
		v[0]++;
	}
	strtab[wcount] = NULL;
	return (strtab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**strtab;
	int		v[4];

	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	strtab = (char**)malloc(sizeof(*strtab) * (ft_wordcounter(str) + 1));
	strtab = ft_word_extractor(str, strtab, ft_wordcounter(str), v);
	return (strtab);
}
