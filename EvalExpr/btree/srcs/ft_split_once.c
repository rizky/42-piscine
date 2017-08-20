/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:48:21 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/14 15:48:22 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char to_find)
{
	int i;

	if (to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
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

char	**ft_word_extractor(char *str, char **strtab, char *charset, int v[5])
{
	int par;

	par = 0;
	while (str[v[4]])
		v[4]++;
	while (v[0] <= v[4])
	{
		if (ft_strstr(charset, str[v[0]]) != NULL && (par == 0))
		{
			if (v[3] == 1)
			{
				strtab[v[1]] = ft_strcpy(v[2], str, v[0]);
				v[1]++;
				v[2] = 0;
				v[3] = 0;
				charset = "\0";
			}
		}
		else
		{
			if (!ft_strstr("(", str[v[0]]))
				par++;
			if (!ft_strstr(")", str[v[0]]))
				par--;
			v[3] = 1;
			v[2]++;
		}
		v[0]++;
	}
	strtab[v[1]] = NULL;
	return (strtab);
}

char	**ft_split_once(char *str, char *charset)
{
	char	**strtab;
	int		v[5];

	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	v[4] = 0;
	strtab = (char**)malloc(sizeof(*strtab) * (3 + 1));
	strtab = ft_word_extractor(str, strtab, charset, v);
	return (strtab);
}
