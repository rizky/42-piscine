/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:34:08 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/23 13:34:08 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_file(char *prog_name, char *arg)
{
	int		fd;

	errno = 0;
	fd = open(arg, O_RDWR);
	if (fd == -1)
		ft_error(prog_name, arg);
	else
		ft_read_input(fd, 0, 1);
	if (close(fd) == -1 && fd != -1)
		ft_putstr("Failed to close");
}
