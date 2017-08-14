#include "ft_stock_par.h"

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	char *c;

	c = str;
	while (*c != '\0')
	{
		ft_putchar(*c);
		c++;
	}
}

void	ft_putnbr(int nb)
{
	int tens;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb = nb * -1;
	}
	tens = 1;
	while (tens < nb / 10)
		tens = tens * 10;
	while (tens > 0)
	{
		ft_putchar(nb / tens + '0');
		nb = nb % tens;
		tens = tens / 10;
	}
}

void   ft_show_tab(struct s_stock_par *par)
{
    int i;
	int j;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size_param);
		ft_putstr("\n");
		j = 0;
		while (par[i].tab[j])
		{
			ft_putstr(par[i].tab[j]);
			ft_putstr("\n");
			i++;
		}
		i++;
	}
}