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

char	*g_input;
int		g_nrow;
int		g_ncol;
char	*g_map_char;
char	**g_tab_string;

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

void	ft_read_input(int fd, int ret, int buf_size)
{
	char	*buf;
	int		state;
	char	*first_line;
	char	*map_desc;

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
			if (ft_strcmp(buf, "\n") != 0)
				first_line = ft_strcat(first_line, buf);
		}
		else if (state == 2)
		{
			first_line = ft_strcat(first_line, "\n");
			ft_extract_map_desc(map_desc, first_line);
			g_tab_string = (char**)malloc(sizeof(char*) * (g_nrow + 1));
			g_tab_string[state - 2] = ft_strdup(first_line);
			buf_size = g_ncol;
			free(buf);
			buf = (char*)malloc(sizeof(char) * (buf_size + 1));
			state++;
		}
		else
		{
			g_tab_string[state - 2] = ft_strdup(buf);
			state++;
		}
	}
}

int		*ft_find_square(int **board, int nrow, int ncol)
{
	int i;
	int j;
	int size;
	int nobs;
	int tl;
	int tr;
	int bl;
	int br;
	int *solution;

	i = 0;
	size = 1;
	solution = (int*)malloc(sizeof(int) * 3);
	solution[0] = 0;
	solution[1] = 0;
	solution[2] = 0;
	while ((i + size - 1) < nrow)
	{
		j = 0;
		while ((j + size - 1) < ncol)
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
				if (solution[2] < size && nobs == 0)
				{
					solution[0] = i;
					solution[1] = j;
					solution[2] = size;
				}
				if (nobs == 0)
					size++;
			}
			j++;
		}
		i++;
	}
	return (solution);
}

void	ft_add_solution(char **tab_string, int solution[3], char *map_char)
{
	int i;
	int j;

	i = solution[0];
	while (i < solution[0] + solution[2])
	{
		j = solution[1];
		while (j < solution[1] + solution[2])
		{
			tab_string[i][j] = g_map_char[2];
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int **board;
	int *solution;

	i = 1;
	if (argc < 2)
	{
		ft_read_input(0, 0, 1);
		board = ft_input_to_array(g_tab_string, g_nrow, g_ncol - 1, g_map_char);
		ft_count_obstacle(board, g_nrow, g_ncol - 1);
		solution = ft_find_square(board, g_nrow, g_ncol - 1);
		ft_add_solution(g_tab_string, solution, g_map_char);
		ft_print_tab_string(g_tab_string, g_ncol);
	}
	else
	{
		while (i < argc)
		{
			ft_file(argv[0], argv[i]);
			board = ft_input_to_array(g_tab_string, g_nrow, g_ncol - 1, g_map_char);
			ft_count_obstacle(board, g_nrow, g_ncol - 1);
			solution = ft_find_square(board, g_nrow, g_ncol - 1);
			ft_add_solution(g_tab_string, solution, g_map_char);
			ft_print_tab_string(g_tab_string, g_ncol);
			i++;
		}
	}
	return (0);
}
