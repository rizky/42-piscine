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
	if (close(fd) == -1 && fd != -1)
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

void		ft_count_obstacle(int **board, int nrow, int ncol)
{
	int i;
	int j;

	i = 1;
	while (i < nrow)
	{
		j = 1;
		while (j < ncol)
		{
			board[i][j] += board[i][j - 1] + board[i -1][j] - board[i - 1][j - 1];
			j++;
		}
		i++;
	}	
}

void		ft_print_solution(char *str, int row, int col, int size)
{
	int c;
	int i;
	int crow;
	int ccol;

	c = 0;
	while ((str[c] != '\0') && (str[c] != '\n'))
		c++;
	c++;
	i = 0;
	while (str[c])
	{
		ccol = i % ft_get_col(g_input);
		crow = i / ft_get_col(g_input);
		if(((ccol >= col) && (ccol <= col + size - 1) )&& ((crow >= row) && (crow <= row + size - 1)))
			ft_putchar('x');
		else
			ft_putchar(str[c]);
		c++;
		if (str[c] != '\n')
			i++;
	}
}

void		ft_find_square(int **board, int nrow, int ncol)
{
	int i;
	int j;
	int size;
	int nobs;
	int tl;
	int tr;
	int bl;
	int br;
	int max_size;
	int max_row;
	int max_col;

	i = 0;
	size = 1;
	max_row = 0;
	max_col = 0;
	max_size = 0;
	while ((i + size - 1) < nrow)
	{
		j = 0;
		while ((j + size -1) < ncol)
		{
			nobs = 0;
			while (nobs == 0 && (size + i - 1 < nrow) && (size + j - 1 < ncol))
			{
				if (i > 0 && j > 0)
					tl = board[i - 1][j - 1];
				else 
					tl = 0;
				if (i > 0)
					tr = board[i - 1][j + size - 1];
				else
					tr = 0;
				if (j > 0)
					bl = board[i + size - 1][j - 1];
				else
					bl = 0;
				br = board[i + size - 1][j + size - 1];
				nobs = br - bl - tr + tl;
				if (max_size < size && nobs == 0)
				{
					max_size = size;
					max_row = i;
					max_col = j;
				}
				if (nobs == 0)
					size++;
			}
			j++;
		}
		i++;
	}
	ft_putnbr(max_size);
	ft_putstr(" - ");
	ft_putnbr(max_row);
	ft_putstr(" - ");
	ft_putnbr(max_col);
	ft_putstr("\n");
	ft_print_solution(g_input, max_row, max_col, max_size);
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
		ft_putstr(g_input);
		ft_putstr("\n");
		ft_count_obstacle(board, ft_get_row(g_input), ft_get_col(g_input));
		ft_find_square(board, ft_get_row(g_input), ft_get_col(g_input));
	}
	else
	{
		while (i < argc)
		{
			g_input = (char*)malloc(sizeof(char));
			ft_display_file(argv[0], argv[i]);
			board = ft_input_to_array(g_input, ft_get_row(g_input), ft_get_col(g_input));
			ft_putstr(g_input);
			ft_putstr("\n");
			ft_count_obstacle(board, ft_get_row(g_input), ft_get_col(g_input));
			ft_find_square(board, ft_get_row(g_input), ft_get_col(g_input));
			i++;
		}
	}
	return (0);
}
