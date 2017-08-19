#include "ft.h"

#define BUF_SIZE 500

// cat rush-00.txt| ./rush-2

char	*ft_read_stdin()
{
	char 	*input;
	char	*buf;
	int		ret;

	input = 0;
	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(0, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		// ft_putstr(buf);
		input = ft_strcat("a",buf);
	}
	return (input);
}

int		ft_get_col(char *str);
int		ft_get_row(char *str);

int main()
{
	char 	*input;
	// int		col;
	// int		row;
    
	// input = ft_read_stdin();
	ft_putstr(ft_strcat("hello", "world"));
	// col = ft_get_col(input);
	// row = ft_get_row(input);

	// rush00(4, 4);
	// if (strcmp(input, rush00(row, col)))
	// {
	// 	ft_putstr("[rush00]");
	// 	ft_putnbr(row);
	// 	ft_putnbr(col);
	// }
	// else if (strcmp(input, rush01(row, col)))
	// 	ft_putstr("rush01");
	// else if	(strcmp(input, rush02(row, col)))
	// 	ft_putstr("rush02");
	// else if	(strcmp(input, rush03(row, col)))
	// 	ft_putstr("rush03");
	// else if	(strcmp(input, rush04(row, col)))
	// 	ft_putstr("rush04");

	return (0);
}