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
#include <stdio.h>

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

void	ft_find_square(int **board, int nrow, int ncol, int **solution)
{
	int pos[2];
	int size;
	int obs;

	pos[0] = 0;
	size = 1;
	while ((pos[0] + size - 1) < nrow)
	{
		pos[1] = 0;
		while ((pos[1] + size - 1) < ncol)
		{
			obs = 0;
			while (obs == 0 && (size + pos[0] - 1 < nrow) && (size + pos[1] - 1 < ncol))
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

int		ft_run_bsq(char **tab_string, int nrow, int ncol, char *map_char)
{
	int **board;
	int *solution;

	solution = (int*)malloc(sizeof(int) * 3);
	solution[0] = 0;
	solution[1] = 0;
	solution[2] = 0;
	board = ft_input_to_array(tab_string, nrow, ncol - 1, map_char);
	ft_count_obstacle(board, nrow, ncol - 1);
	ft_find_square(board, nrow, ncol - 1, &solution);
	ft_add_solution(tab_string, solution, map_char);
	ft_print_tab_string(tab_string, ncol);
	printf("%d - %d - %d\n", solution[0], solution[1], solution[2]);
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
	{
		ft_read_input(0, 0, 1);
		ft_run_bsq(g_tab_string, g_nrow, g_ncol, g_map_char);
	}
	else
	{
		while (i < argc)
		{
			ft_file(argv[0], argv[i]);
			ft_run_bsq(g_tab_string, g_nrow, g_ncol, g_map_char);
			i++;
		}
	}
	return (0);
}
