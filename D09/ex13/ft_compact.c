/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:31:52 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/11 14:31:53 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_compact_count(char **tab, int length)
{
	int	i;
	int	compact_len;

	i = 0;
	compact_len = 0;
	while (i < length)
	{
		if (tab[i][0] != '\0')
		{
			compact_len++;
		}
		i++;
	}
	return (compact_len);
}

void	ft_copy_tab(char **dest, char **src, int length, int compact_len)
{
	int i;

	i = 0;
	while (i < compact_len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < length)
	{
		dest[i][0] = '\0';
		free(dest[i]);
		i++;
	}
}

int		ft_compactb(char **tab, int length)
{
	int		i;
	int		j;
	char	**compacttab;
	int		compact_len;

	compact_len = ft_compact_count(tab, length);
	compacttab = (char**)malloc(sizeof(*compacttab) * (compact_len + 1));
	i = 0;
	j = 0;
	while (i < length)
	{
		if (tab[i][0] != '\0')
		{
			compacttab[j] = tab[i];
			j++;
		}
		i++;
	}
	ft_copy_tab(tab, compacttab, length, compact_len);
	return (compact_len);
}

int		ft_compact(char **tab, int length)
{
	int		counter1;
	int		counter2;

	counter1 = 0;
	counter2 = 0;
	while (counter1 < length)
	{
		if (tab[counter1] == 0)
			counter2++;
		else
			tab[counter1 - counter2] = tab[counter1];
		counter1++;
	}
	tab[counter1 - counter2] = 0;
	return (counter1 - counter2);
}