/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 01:18:30 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 16:40:10 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_tab(int *tab, int number)
{
	int i;

	i = 0;
	while (i < number)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

int		ft_check_comb(int *tab, int number)
{
	int i;
	int ok;
	int prev;

	i = 0;
	ok = 1;
	prev = -1;
	while (i < number)
	{
		if (prev >= tab[i])
			ok = 0;
		prev = tab[i];
		i++;
	}
	return (ok);
}

void	ft_increase_tab(int *tab, int number)
{
	int tens;
	int i;

	tens = 0;
	i = number - 1;
	if(tab[0] == 1 && tab[8] == 0 && number == 9)
		while (i++ < number)
			tab[i] = i + 1;
	else
	{
		while (--i >= 0)
		{
			if (i == number - 1)
				tab[i] = tab[i] + 1;
			else
			{
				tab[i] = tab[i] + tens;
				tens = 0;
			}
			if (tab[i] == 10)
			{
				tab[i] = 0;
				tens = 1;
			}
		}
	}
}

void	ft_print_combn(int number)
{
	int tab[number];
	int i;
	int first;

	i = 0;
	first = 1;
	while (i++ < number + 1)
		tab[i - 1] = 0;
	if (number > 0 && number < 10)
		while (tab[0] < 9)
		{
			if (ft_check_comb(tab, number))
			{
				if (!first)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				else
					first = 0;
				ft_print_tab(tab, number);
				if ((number == 9 && tab[0] == 1 && tab[8] == 9))
					break ;
			}
			ft_increase_tab(tab, number);
		}
}
