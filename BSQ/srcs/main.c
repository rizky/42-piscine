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

int		ft_extract_map(int fd, char *map_desc, char *buf, char *first_line)
{
	int		ret;
	int		len_map_desc;
	int		i;

	len_map_desc = ft_strlen(map_desc);
	g_nrow = ft_atoi(map_desc);
	g_ncol = ft_strlen(first_line);
	g_map_char = (char*)malloc(sizeof(char) * (3 + 1));
	g_map_char[2] = map_desc[len_map_desc - 1];
	g_map_char[1] = map_desc[len_map_desc - 2];
	g_map_char[0] = map_desc[len_map_desc - 3];
	g_tab_string = (char**)malloc(sizeof(char*) * (g_nrow + 1));
	g_tab_string[0] = ft_strdup(first_line);
	buf = (char*)malloc(sizeof(char) * (g_ncol + 1));
	i = 1;
	while ((ret = read(fd, buf, g_ncol)))
	{
		g_tab_string[i] = ft_strdup(buf);
		if (buf[g_ncol - 1] != '\n')
			return (0);
		i++;
	}
	if (i < g_nrow)
		return (0);
	return (1);
}

int		ft_read_input(int fd, int state, int buf_size)
{
	char	*buf;
	int		ret;
	char	*first_line;
	char	*map_desc;

	buf = (char*)malloc(sizeof(char) * (buf_size + 1));
	map_desc = (char*)malloc(sizeof(char));
	first_line = (char*)malloc(sizeof(char));
	while (state == 0 && (ret = read(fd, buf, buf_size)))
	{
		buf[ret] = '\0';
		if (ft_strcmp(buf, "\n") == 0)
			state++;
		else
			map_desc = ft_strcat(map_desc, buf);
	}
	while (state == 1 && (ret = read(fd, buf, buf_size)))
	{
		buf[ret] = '\0';
		if (ft_strcmp(buf, "\n") == 0)
			state++;
		first_line = ft_strcat(first_line, buf);
	}
	return (ft_extract_map(fd, map_desc, buf, first_line));
}

void	ft_find_square(int **board, int nrow, int ncol, int **solution)
{
	int pos[2];
	int size;
	int obs;
	int is_inside;

	pos[0] = 0;
	size = 1;
	while ((pos[0] + size - 1) < nrow)
	{
		pos[1] = 0;
		while ((pos[1] + size - 1) < ncol)
		{
			obs = 0;
			is_inside = (size + pos[0] - 1 < nrow);
			while (!obs && is_inside && (size + pos[1] - 1 < ncol))
			{
				obs = ft_get_obstacle(board, pos, size, solution);
				if (obs == 0)
					size++;
			}
			pos[1]++;
		}
		pos[0]++;
	}
}

void	ft_run_bsq(char **tab_string, int nrow, int ncol, char *map_char)
{
	int **board;
	int *solution;
	int dim[2];

	solution = (int*)malloc(sizeof(int) * 3);
	solution[0] = 0;
	solution[1] = 0;
	solution[2] = 0;
	dim[0] = nrow;
	dim[1] = ncol - 1;
	board = (int**)malloc(sizeof(int*) * (dim[0] + 1));
	if (ft_input_to_array(tab_string, &board, dim, map_char))
	{
		ft_count_obstacle(board, nrow, ncol - 1);
		ft_find_square(board, nrow, ncol - 1, &solution);
		ft_add_solution(tab_string, solution, map_char);
		ft_print_tab_string(tab_string, ncol);
	}
	else
		ft_map_error();
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
	{
		if (ft_read_input(0, 0, 1))
			ft_run_bsq(g_tab_string, g_nrow, g_ncol, g_map_char);
		else
			ft_map_error();
	}
	else
	{
		while (i < argc)
		{
			if (ft_file(argv[0], argv[i]))
				ft_run_bsq(g_tab_string, g_nrow, g_ncol, g_map_char);
			else
				ft_map_error();
			i++;
		}
	}
	return (0);
}
