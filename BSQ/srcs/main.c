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

char 	*g_input;

void	ft_read_file(int fd)
{
	char	*buf;
	int		ret;

	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		g_input = ft_strcat(g_input, buf);
	}
	
}

void	ft_read_stdin(void)
{
	char	*buf;
	int		ret;

	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(0, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		g_input = ft_strcat(g_input, buf);
	}
}

void	ft_display_file(char *prog_name, char *arg)
{
	int		fd;

	errno = 0;
	fd = open (arg, O_RDWR);
	if (fd == -1)
			ft_error(prog_name, arg);
	else
		ft_read_file(fd);
	if (close(fd) == -1 && fd == 3)
		ft_putstr("Failed to close");
}

int		ft_get_col(char *str)
{
	int len;

	len = 0;
	while ((str[len] != '\0') && (str[len] != '\n'))
		len++;
	return (len);
}
int		ft_get_row(char *str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			len++;
		i++;
	}
	return (len);
}

int		**ft_input_to_array(char *str, int nrow, int ncol)
{
	int board[nrow][ncol];
	int i;
	int j;

	i = 0
	while (i < nrow)
	{
		j = 0
		while (j < ncol)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	
}

int		main(int argc, char **argv)
{
	int i;

	g_input = (char*)malloc(sizeof(char));
	i = 1;
	if (argc < 2)
		ft_read_stdin();
	else
	{
		while (i < argc)
		{
			ft_display_file(argv[0], argv[i]);
			i++;
		}
	}
	ft_putstr(g_input, ft_get_row(g_input), ft_get_col(g_input));

	return (0);
}
