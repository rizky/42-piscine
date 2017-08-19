/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzerz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 17:42:12 by mbouzerz          #+#    #+#             */
/*   Updated: 2017/08/06 17:42:39 by mbouzerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	ft_first(int x)
{
	int index;

	ft_putchar('o');
	index = x - 1;
	while (index > 1)
	{
		ft_putchar('-');
		index--;
	}
	if (x > 1)
	{
		ft_putchar('o');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('\n');
	}
}

void	ft_middle(int x)
{
	int index;

	ft_putchar('|');
	index = x - 1;
	while (index > 1)
	{
		ft_putchar(' ');
		index--;
	}
	if (x > 1)
	{
		ft_putchar('|');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('\n');
	}
}

void	rush00(int x, int y)
{
	int index;

	if (x <= 0 || y <= 0)
	{
		ft_putchar(0);
	}
	else
	{
		ft_first(x);
		index = y - 1;
		while (index > 1)
		{
			ft_middle(x);
			index--;
		}
		if (y > 1)
		{
			ft_first(x);
		}
	}
}
