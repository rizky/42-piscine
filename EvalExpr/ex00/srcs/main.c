#include "ft.h"
#include "ft_btree.h"

int main(int ac, char **av)
{
	char 	**input;
	int		i;

	if (ac > 1)
	{
		input = ft_split(av[1], "+");
		i = 0;
		while (input[i])
		{
			ft_putstr(input[i]);
			ft_putstr("\n");
			i++;
		}
	}
	return (0);
}