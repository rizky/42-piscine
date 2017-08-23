/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:19:15 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/23 13:19:15 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_tab_string(char **tab_string, int ncol)
{
	int i;

	i = 0;
	while (tab_string[i])
	{
		ft_putstr_at_once(tab_string[i], ncol);
		i++;
	}
}

void	ft_print_array(int **board, int nrow, int ncol)
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

void	ft_count_obstacle(int **board, int nrow, int ncol)
{
	int i;
	int j;
	int l;
	int t;

	i = 0;
	while (++i < nrow)
		board[i][0] += board[i - 1][0];
	i = 0;
	while (++i < ncol)
		board[0][i] += board[0][i - 1];
	i = 1;
	while (i < nrow)
	{
		j = 1;
		while (j < ncol)
		{
			l = board[i][j - 1];
			t = board[i - 1][j];
			board[i][j] += l + t - board[i - 1][j - 1];
			j++;
		}
		i++;
	}
}

int		**ft_input_to_array(char **str, int nrow, int ncol, char *map_char)
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
			if (str[i][j] == map_char[0])
				board[i][j] = 0;
			else if (str[i][j] == map_char[1])
				board[i][j] = 1;
			j++;
		}
		i++;
	}
	return (board);
}
