/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:39:28 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/11 14:39:29 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_unmatch(int *tab, int length)
{
	int		i;
	int		unmatch;

	unmatch = 0;
	ft_sort_integer_table(tab, length);
	i = 0;
	while (i < length)
	{
		unmatch = tab[i];
		if ((tab[i] - tab[i + 1]) != 0)
			break ;
		i = i + 2;
	}
	return (unmatch);
}
