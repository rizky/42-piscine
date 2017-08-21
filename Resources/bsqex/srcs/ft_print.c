/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 21:32:49 by scornaz           #+#    #+#             */
/*   Updated: 2017/08/21 22:00:52 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_put_square(char *map, int pos, int size, int y)
{
	int i;
	int j;

	i = 0;
	while (i++ < pos)
		map++;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			*map++ = '#';
			j++;
		}
		map += y - size;
		i++;
	}
}

void	ft_print(char *map)
{
	while (*map)
		write(1, map++, 1);
}
