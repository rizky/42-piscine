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
int		g_nrow;
int		g_ncol;
char	*g_map_char;
char 	**g_tab_string;

void	ft_extract_map_desc(char *map_desc, char *first_line)
{
	int len_map_desc;

	len_map_desc = ft_strlen(map_desc);
	g_nrow = ft_atoi(map_desc);
	g_ncol = ft_strlen(first_line);
	g_map_char = (char*)malloc(sizeof(char) * (3 + 1));
	g_map_char[2] = map_desc[len_map_desc - 1];
	g_map_char[1] = map_desc[len_map_desc - 2];
	g_map_char[0] = map_desc[len_map_desc - 3];
}

void	ft_read_input(int fd)
{
	char	*buf;
	int		ret;
	int		buf_size;
	int		state;
	char	*first_line;
	char 	*map_desc;

	buf_size = 1;
	state = 0;
	buf = (char*)malloc(sizeof(char) * (buf_size + 1));
	map_desc = (char*)malloc(sizeof(char));
	first_line = (char*)malloc(sizeof(char));
	while ((ret = read(fd, buf, buf_size)))
	{
		buf[ret] = '\0';
		if (ft_strcmp(buf, "\n") == 0)
			state++;
		if (state == 0)
			map_desc = ft_strcat(map_desc, buf);
		else if (state == 1)
		{
			if(ft_strcmp(buf, "\n") != 0)
				first_line = ft_strcat(first_line, buf);
		}
		else if (state == 2)
		{
			first_line = ft_strcat(first_line, "\n");
			ft_extract_map_desc(map_desc, first_line);
			g_tab_string = (char**)malloc(sizeof(char*) * (g_nrow + 1));
			g_tab_string[state - 2] = ft_strdup(first_line);
			buf_size = g_ncol;
			state++;
		}
		else
		{
			g_tab_string[state - 2] = ft_strdup(buf);
			state++;
		}
	}
	ft_print_tab_string(g_tab_string);
}

void	ft_display_file(char *prog_name, char *arg)
{
	int		fd;

	errno = 0;
	fd = open(arg, O_RDWR);
	if (fd == -1)
			ft_error(prog_name, arg);
	else
		ft_read_input(fd);
	if (close(fd) == -1 && fd != -1)
		ft_putstr("Failed to close");
}

int		**ft_input_to_array(char **str, int nrow, int ncol)
{
	int **board;
	int i;
	int j;

	board = (int**)malloc(sizeof(int*) * (nrow + 1));
	i = 0;
	while (i < nrow)
	{
		j = 0;
		board[i] = (int*)malloc(sizeof(int) * (ncol));
		while (j < ncol)
		{
			if (str[i][j] == g_map_char[0])
				board[i][j] = 0;
			else if (str[i][j] == g_map_char[1])
				board[i][j] = 1;
			j++;
		}
		i++;
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
		while (j < ncol - 1)
		{
			ft_putnbr(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}	
}

void		ft_print_tab_string(char **tab_string)
{
	int i;

	i = 0;
	while (tab_string[i])
	{
		ft_putstr_at_once(tab_string[i], g_ncol);
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
		board[i][0] += board[i - 1][0];
		i++;
	}
	i = 1;
	while (i < ncol)
	{
		board[0][i] += board[0][i - 1];
		i++;
	}
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

void		ft_print_solution(char **tab_string, int row, int col, int size)
{
	int i;
	int j;

	i = row;
	while (i < row + size)
	{
		j = col;
		while (j < col + size)
		{
			tab_string[i][j] = g_map_char[2];
			j++;
		}
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
	ft_print_solution(g_tab_string, max_row, max_col, max_size);
}

int		main(int argc, char **argv)
{
	int i;
	int **board;

	i = 1;
	if (argc < 2)
	{
		ft_read_input(0);
		board = ft_input_to_array(g_tab_string, g_nrow, g_ncol - 1);
		ft_count_obstacle(board, g_nrow, g_ncol - 1);
		ft_find_square(board, g_nrow, g_ncol - 1);
		ft_print_tab_string(g_tab_string);
	}
	else
	{
		while (i < argc)
		{
			ft_display_file(argv[0], argv[i]);
			board = ft_input_to_array(g_tab_string, g_nrow, g_ncol - 1);
			ft_count_obstacle(board, g_nrow, g_ncol - 1);
			ft_find_square(board, g_nrow, g_ncol - 1);
			ft_print_tab_string(g_tab_string);
			i++;
		}
	}
	return (0);
}
