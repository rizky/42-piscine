/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_integer_table.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:03:13 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 22:51:18 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int *ptri;
	int *ptrj;
	int i;
	int j;

	i = 0;
	ptri = tab;
	while (i < size)
	{
		j = i + 1;
		ptrj = ptri + 1;
		while (j < size)
		{
			if (*ptri > *ptrj)
				ft_swap(ptri, ptrj);
			j++;
			ptrj++;
		}
		i++;
		ptri++;
	}
}
