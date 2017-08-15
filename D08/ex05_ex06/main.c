#include <stdio.h>
#include "ft_stock_par.h"

int main(int argc, char **argv)
{
	struct	s_stock_par *stock;

	stock = ft_param_to_tab(argc, argv);
	ft_show_tab(stock);
}	