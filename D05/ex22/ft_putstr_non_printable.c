/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:59:32 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/09 09:59:33 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_putnbr_base(int nbr, char *base)
{
	int			ibase;
	int			sign;

	ibase = ft_strlen(base);
	sign = 1;
	if (nbr < 0)
	{
		ft_putchar('-');
		sign = -1;
		nbr = sign * nbr;
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

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ')
		{
			ft_putchar('\\');
			if (str[i] - '\0' < 16)
				ft_putchar('0');
			ft_putnbr_base(str[i] - '\0', "0123456789abcdef");
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
