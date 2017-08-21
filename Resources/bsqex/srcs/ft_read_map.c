/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 20:05:56 by nschwarz          #+#    #+#             */
/*   Updated: 2017/08/21 19:36:49 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_read_map(char *path)
{
	int fd;
	int ret;
	char *final;
	char buf[65];
	int i;

	i = 0;
	final = (char*)malloc(sizeof(char) * 150);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		NO_FILE;
		return (0);
	}
	while ((ret = read(fd, buf, 64)))
	{
		i += ret;
		strncat(final, buf, ret);
	}
	final[i] = '\0';
	i = 0;
	while (final[i++] != '\n')
		;
	return (final + i);
}
