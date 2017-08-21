/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:53:29 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/21 17:53:29 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_error(char *prog_name, char *arg)
{
	if (errno == EACCES)
	{
		ft_putstr(prog_name);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": Permission Denied\n");
	}
	else if (errno == EISDIR)
	{
		ft_putstr(prog_name);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": Is a directory\n");
	}
	else
	{
		ft_putstr(prog_name);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": No such file or directory\n");
		ft_putstr(prog_name);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": Bad file descriptor\n");
	}
}
