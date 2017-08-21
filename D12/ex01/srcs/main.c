/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:47:22 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/21 17:47:23 by rnugroho         ###   ########.fr       */
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
	}
}

void	ft_read_file(int fd, char *buffer)
{
	int read_i;

	while ((read_i = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[read_i] = '\0';
		ft_putstr(buffer);
	}
}

void	ft_display_file(char *prog_name, char *arg)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];

	errno = 0;
	fd = open(arg, O_RDWR);
	if (fd == -1)
	{
		if (arg[0] == '-' && arg[1] == '\0')
			ft_read_stdin();
		else
			ft_error(prog_name, arg);
	}
	else
		ft_read_file(fd, buffer);
	if (close(fd) == -1 && fd == 3)
		ft_putstr("Failed to close");
}

void	ft_read_stdin(void)
{
	int		read_i;
	char	buffer[BUFFER_SIZE + 1];

	read_i = 0;
	while ((read_i = read(0, buffer, BUFFER_SIZE)))
	{
		buffer[read_i] = '\0';
		ft_putstr(buffer);
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		ft_read_stdin();
	else
	{
		while (i < argc)
		{
			ft_display_file("cat", argv[i]);
			i++;
		}
	}
	return (0);
}
