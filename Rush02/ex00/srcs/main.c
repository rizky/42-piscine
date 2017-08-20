#include "ft.h"

#define BUF_SIZE 5

char	*ft_read_stdin()
{
	char 	*input;
	char	*buf;
	int		ret;

	input = (char*)malloc(sizeof(char));;
	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(0, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		input = ft_strcat(input, buf);
	}
	return (input);
}

int		ft_get_col(char *str)
{
	int len;

	len = 0;
	while ((str[len] != '\0') && (str[len] != '\n'))
		len++;
	return (len);
}
int		ft_get_row(char *str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			len++;
		i++;
	}
	return (len);
}

void	ft_print_result(char *type, int col, int row)
{
	ft_putstr(type);
	ft_putchar(' ');
	ft_putchar('[');
	ft_putnbr(col);
	ft_putchar(']');
	ft_putchar(' ');
	ft_putchar('[');
	ft_putnbr(row);
	ft_putchar(']');
	ft_putchar('\n');
}

int main()
{
	char 	*input;
	char 	*base;
	int		col;
	int		row;
    
	input = ft_read_stdin();
	col = ft_get_col(input);
	row = ft_get_row(input);

	base = rush00(col, row, ft_strlen(input));
	if (ft_strcmp(input, base) == 0)
	{
		ft_print_result("[rush-00]", col, row);
	}
	base = rush01(col, row, ft_strlen(input));
	if (ft_strcmp(input, base) == 0)
	{
		ft_print_result("[rush-01]", col, row);
	}
	return (0);
}