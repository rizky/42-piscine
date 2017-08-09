/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 02:00:26 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/09 02:07:07 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int len;
	int i;

	if (min > max)
		return (0);
	len = max - min;
	tab = (int*)malloc(sizeof(*tab) * (len + 1));
	i = 0;
	while (i < len)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (len);
}
