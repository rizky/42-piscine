/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:00:35 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/15 13:00:37 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	char *c;

	c = str;
	while (*c != '\0')
	{
		ft_putchar(*c);
		c++;
	}
}

void	ft_putnbr(int nb)
{
	const char *base = "0123456789";

	if ((nb / 10) > 0)
		ft_putnbr(nb / 10);
	ft_putchar(base[nb % 10]);
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;
	int j;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		ft_putnbr(par[i].size_param);
		ft_putstr("\n");
		j = 0;
		while (par[i].tab[j])
		{
			ft_putstr(par[i].tab[j]);
			ft_putstr("\n");
			j++;
		}
		i++;
	}
}
