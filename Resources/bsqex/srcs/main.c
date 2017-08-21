/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:53:49 by scornaz           #+#    #+#             */
/*   Updated: 2017/08/21 21:52:04 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int get_Y(char *map)
{
	int size;

	size = 0;
	while (*map++ != '\n')
		size++;
	return (size + 1);
}

int get_X(char *map)
{
	int size;

	size = 0;
	while (*map)
		if (*map++ == '\n')
			size++;
	return (size);
}

int main(int argc, char **argv)
{
	char	*map;
	t_bsq	*result;
	t_bsq	res;
	int x;
	int y;

	res.size = 0;
	if (argc != 2)
		return (1);
	map = ft_read_map(argv[1]);
	x = get_X(map);
	y = get_Y(map);
	result = resolve(map, x, y);
	while (result->size != -1)
	{
		if (result->size > res.size)
			res = *result;
		result++;
	}
//	printf("pos :%d et size:%d\n", res.pos, res.size);
	ft_put_square(map, res.pos, res.size, y);
	ft_print(map);
	return (0);
}
