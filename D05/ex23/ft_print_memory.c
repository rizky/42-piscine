/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 19:08:01 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/09 19:08:04 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnbr_base(long long nbr, char *base)
{
	if ((nbr) > 0)
	{
		if ((nbr / 16) != 0)
			ft_putnbr_base(nbr / 16, base);
		ft_putchar(base[(nbr % 16)]);
	}
	else if (nbr == 0)
		ft_putchar(base[(nbr % 16)]);
}

void	ft_print_address(void *addr, unsigned int i, unsigned int size)
{
	int div;
	int dig;

	if ((i % 16 == 0))
	{
		div = i;
		dig = 0;
		while (div > 0)
		{
			div = div / 255;
			dig++;
		}
		div = -1;
		while (div++ < 5 - dig)
			ft_putchar('0');
		ft_putchar('0');
		ft_putnbr_base(i, "0123456789abcdef");
		ft_putchar(':');
		ft_putchar(' ');
	}
	if (i < size)
	{
		if (*(unsigned char*)addr - '\0' < 16)
			ft_putchar('0');
	}
}

void	ft_print_char(void *addr, unsigned int i, unsigned int size, int round)
{
	unsigned char	*j;
	unsigned int	k;

	if (i > 14 && (((i - 15) % 16) == 0))
	{
		j = addr - 16;
		k = 0;
		while ((j++ < (unsigned char*)addr))
			if ((k++ < 16 - (round - size)) || (i < size))
			{
				if ((*j - '\0' >= 32) && (*j - '\0' < 127))
					ft_putchar(*j);
				else
					ft_putchar('.');
			}
		ft_putchar('\n');
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	round;

	i = 0;
	round = size;
	while (round % 16 != 0)
		round++;
	while (i < round)
	{
		ft_print_address(addr, i, size);
		if (i < size)
			ft_putnbr_base(*(unsigned char*)addr - '\0', "0123456789abcdef");
		if (i >= size)
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
		ft_print_char(addr, i, size, round);
		addr++;
		i++;
	}
	return (addr);
}
