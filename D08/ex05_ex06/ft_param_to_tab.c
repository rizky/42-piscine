/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:50:03 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/14 16:50:04 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen1(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char				*ft_strcpy1(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *stock;
	int			i;
	int			j;

	stock = (t_stock_par*)malloc(sizeof(stock) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		stock[i].size_param = ft_strlen1(av[i]);
		stock[i].str = av[i];
		stock[i].copy = (char*)malloc(sizeof(char) * (ft_strlen1(av[i]) + 1));
		stock[i].copy = ft_strcpy1(stock[i].copy, av[i]);
		stock[i].tab = ft_split_whitespaces(av[i]);
		ft_putstr(stock[i].str);
		ft_putstr("\n");
		ft_putnbr(stock[i].size_param);
		ft_putstr("\n");
		j = 0;
		while (stock[i].tab[j])
		{
			ft_putstr(stock[j].tab[j]);
			ft_putstr("\n");
			i++;
		}
		i++;
	}
	stock[ac].str = NULL;
	return (stock);
}
