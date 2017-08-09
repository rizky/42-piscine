/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 01:44:40 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/09 01:58:44 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int len;
	int i;

	if (min > max)
		return (NULL);
	len = max - min;
	tab = (int*)malloc(sizeof(*tab) * (len + 1));
	i = 0;
	while (i < len)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
