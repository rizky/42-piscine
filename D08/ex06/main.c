#include <stdio.h>
#include "ft_stock_par.h"

int main()
{
	struct	s_stock_par *stock;
	int i;
	int j;
	int ac;
	const char * av[] = {
		"First entry",
		"Second entry",
		"Third entry",
	};
	stock = ft_param_to_tab(ac, av);
	ft_show_tab(stock);
}