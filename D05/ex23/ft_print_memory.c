#include <stdlib.h>
#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_strlen(char *str)
{
	char	*c;
	int		len;

	c = str;
	len = 0;
	while (*c)
	{
		len++;
		c++;
	}
	return (len);
}

void	ft_putnbr_base(long long nbr, char *base)
{
	int			ibase;
	int			sign;

	ibase = ft_strlen(base);
	sign = 1;
	if (nbr < 0)
	{
//		ft_putchar('-');
//		sign = -1;
		nbr = 0;
	}
	if ((nbr) > 0)
	{
		if ((nbr / ibase) != 0)
			ft_putnbr_base(nbr / ibase, base);
		ft_putchar(base[(nbr % ibase)]);
	}
	else if (nbr == 0)
		ft_putchar(base[(nbr % ibase)]);
}

void	ft_print_address(int i)
{
	int div;
	int dig;

	if ((i % 16 == 0))
	{
		div= i;
		dig= 0;
		ft_putchar('\n');			
		while( div > 0)
		{
			div = div / 255;
			dig++;
		}
		div = 0;
		while(div < 6 - dig)
		{
			ft_putchar('0');
			div++;
		}
		ft_putchar('0');
		ft_putnbr_base(i, "0123456789abcdef");
		ft_putchar(':');
		ft_putchar(' ');
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
    int		i;
	char	*j;
	int		div;
	int		dig;
	int		round;

	i = 0;
	round = size;
	while(round % 16 != 0)
		round++;

	while (i < round)
	{
		ft_print_address(i);

		if(i < size)
		{
			if(*(char*)addr - '\0' < 16)
				ft_putchar('0');
			ft_putnbr_base(*(char*)addr - '\0', "0123456789abcdef");
			if(i % 2 == 1)
				ft_putchar(' ');
		}
		else
		{
			if(*(char*)addr - '\0' < 16)
				ft_putchar(' ');
			ft_putchar(' ');
			if(i % 2 == 1)
				ft_putchar(' ');
		}
		if(i > 14 && (((i - 15) % 16) == 0))
		{
			ft_putchar(' ');
			j = addr - 15;
			while (j <= (char*)addr)
			{
				if((*(char*)j - '\0' >= 32) && (*(char*)j - '\0' <= 255) && (*(char*)j - '\0' != 127))				
					ft_putchar(*(char*)j);
				else
					ft_putchar('.');
				j++;
			}
		}
		
		if(i < size)
			addr++;
		i++;
	}
	ft_putchar('\n');
	return (addr);
}
