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

int		ft_is_available(int board[8][8], int row, int col)
{
	int i;

	i = 0;
	while (++i <= row)
		if (board[row - i][col] == 1)
			return (0);
	i = 0;
	while ((++i <= row) && (i <= col))
		if (board[row - i][col - i] == 1)
			return (0);
	i = 0;
	while (((row + i) < 8) && ((col - i) >= 0))
	{
		if (board[row + i][col - i] == 1)
			return (0);
		i++;
	}
	i = 1;
	while (((row - i) >= 0) && ((col + i) < 8))
	{
		if (board[row - i][col + i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int		ft_put_queen(int board[8][8], int row, int *solution)
{
	int i;

	if (row == 8)
		return (1);
	i = 0;
	while (i < 8)
	{
		if (ft_is_available(board, row, i))
		{
			board[row][i] = 1;
			if (ft_put_queen(board, row + 1, solution) == 1)
			{
				*solution = *solution + 1;
			}
			board[row][i] = 0;
		}
		i++;
	}
	return (0);
}

int		ft_eight_queens_puzzle(void)
{
	int board[8][8];
	int i;
	int j;
	int solution;

	i = 0;
	solution = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_put_queen(board, 0, &solution);
	return (solution);
}
