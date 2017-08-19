/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:57:05 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/07 12:09:52 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int		ft_check_number(int board[9][9], int row, int col, int number)
{
	int i;
	int j;
	int base_row;
	int base_col;
	int exist;

	exist = 0;
	base_row = (row / 3) * 3;
	base_col = (col / 3) * 3;
	i = base_row;
	while ( i < base_row + 3)
	{
		j = base_col;
		while ( j < base_col + 3)
		{
			if(board[i][j] == number)
			{
				exist = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (exist);
}

int		ft_is_available(int board[9][9], int row, int col, int number)
{
	int i;

	if(ft_check_number(board, row, col, number))
		return (0);
	i = 0;
	while (i < 9)
	{
		if (board[i][col] == number)
			return (0);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (board[row ][i] == number)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_board(int board[9][9])
{
	int i;
	int j;	

 	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			printf(" %d ", board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

int		ft_mcv_heuristic(int board[9][9], int *row, int *col)
{
	int	heu[3];
	int	i;
	int	j;
	int k;
	int l;

	heu[0] = 0;
	heu[1] = 0;
	heu[2] = 10;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			k = 1;
			l = 0;
			while (k <= 9)
			{
				if(board[i][j] != 0)
					l = 10;
				else if(ft_is_available(board, i, j, k))
					l++;
				k++;
			}
			if (heu[2] > l)
			{
				heu[2] = l;
				heu[0] = i;
				heu[1] = j;
			}
			j++;
		}
		i++;
	}
	*row = heu[0];
	*col = heu[1];
	return heu[2];
}

int		ft_put_number(int board[9][9], int row, int col, int *solution)
{
	int number;

	if (ft_mcv_heuristic(board, &row, &col) == 10)
		return (1);
	number = 1;
	while (number <= 9)
	{
		if (ft_is_available(board, row, col, number))
		{
			board[row][col] = number;
			if (ft_put_number(board, row, col + 1, solution))
			{
				*solution = *solution + 1;
				ft_print_board(board);
			}
			if (*solution < 2)
				board[row][col] = 0;
		}
		number++;
	}
	return (0);
}

int		ft_sudoku(int board[9][9])
{

	int solution;

	solution = 0;
	ft_put_number(board, 0, 0, &solution);
	return (solution);
}
