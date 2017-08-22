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
	fd = open(arg, O_RDWR);
	if (fd == -1)
			ft_error(prog_name, arg);
	else
		ft_read_file(fd);
	if (close(fd) == -1 && fd == 3)
		ft_putstr("Failed to close");
}

int		ft_get_col(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while ((str[i] != '\0') && (str[i] != '\n'))
		i++;
	i++;
	while ((str[i] != '\0') && (str[i] != '\n'))
	{
		len++;
		i++;
	}
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
	return (len - 1);
}

int		**ft_input_to_array(char *str, int nrow, int ncol)
{
	int **board;
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	board = (int**)malloc(sizeof(int*) * (nrow + 1));
	while ((str[c] != '\0') && (str[c] != '\n'))
		c++;
	c++;
	board[i] = (int*)malloc(sizeof(int) * (ncol));
	while (str[c])
	{
		if (str[c] == '.')
			board[i][j] = 0;
		else
			board[i][j] = 1;
		if (str[c] == '\n')
		{
			i++;
			board[i] = (int*)malloc(sizeof(int) * ncol);
			j = 0;
		}
		else
			j++;
		c++;
	}
	return (board);
}

void		ft_print_array(int **board, int nrow, int ncol)
{
	int i;
	int j;

	i = 0;
	while (i < nrow)
	{
		j = 0;
		while (j < ncol)
		{
			ft_putnbr(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}	
}

int		main(int argc, char **argv)
{
	int i;
	int **board;

	i = 1;
	if (argc < 2)
	{
		g_input = (char*)malloc(sizeof(char));
		ft_read_stdin();
		board = ft_input_to_array(g_input, ft_get_row(g_input), ft_get_col(g_input));
		ft_print_array(board, ft_get_row(g_input), ft_get_col(g_input));
	}
	else
	{
		while (i < argc)
		{
			g_input = (char*)malloc(sizeof(char));
			ft_display_file(argv[0], argv[i]);
			board = ft_input_to_array(g_input, ft_get_row(g_input), ft_get_col(g_input));
			ft_print_array(board, ft_get_row(g_input), ft_get_col(g_input));
			i++;
		}
	}
	return (0);
}
