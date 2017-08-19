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

char *base;

void	ft_first(int x)
{
	int index;

	base = ft_strcat(base, "o");
	index = x - 1;
	while (index > 1)
	{
		base = ft_strcat(base, "-");
		index--;
	}
	if (x > 1)
	{
		base = ft_strcat(base, "o");
		base = ft_strcat(base, "\n");
	}
	else
	{
		base = ft_strcat(base, "\n");
	}
}

void	ft_middle(int x)
{
	int index;

	base = ft_strcat(base, "|");
	index = x - 1;
	while (index > 1)
	{
		base = ft_strcat(base, " ");
		index--;
	}
	if (x > 1)
	{
		base = ft_strcat(base, "|");
		base = ft_strcat(base, "\n");
	}
	else
	{
		base = ft_strcat(base, "o");
	}
}

char	*rush00(int x, int y, int len)
{
	int index;

	base = (char*)malloc(sizeof(char) * (len + 1));
	if (x <= 0 || y <= 0)
	{
		base = ft_strcat(base, "");
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
	base[len ] = '\0';
	return (base);
}
