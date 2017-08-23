#include "ft.h"

void		ft_print_tab_string(char **tab_string, int ncol)
{
	int i;

	i = 0;
	while (tab_string[i])
	{
		ft_putstr_at_once(tab_string[i], ncol);
		i++;
	}	
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