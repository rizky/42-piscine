/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 01:18:30 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 15:10:00 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnbr(int number)
{
	int tens;
	int i;

	if (number < 0)
	{
		ft_putchar('-');
		number = number * -1;
	}
	tens = 1;
	i = number / 10;
	while (i > 0)
	{
		i = i / 10;
		tens = tens * 10;
	}
	while (tens > 0)
	{
		ft_putchar(number / tens + '0');
		number = number % tens;
		tens = tens / 10;
	}
}

int		ft_checkcomb(int i, int pow)
{
	int ok;
	int div;
	int mod;
	int tens;

	tens = pow;
	mod = i;
	ok = 1;
	div = 0;
	while (mod > 0)
	{
		if ((div >= mod / tens || mod % 10 == 0) && i > 9)
			ok = 0;
		div = mod / tens;
		mod = mod % tens;
		tens = tens / 10;
	}
	return (ok);
}

void	ft_print_combn(int number)
{
	int i;
	int pow;
	int tens;

	i = 0;
	tens = 1;
	while (i++ < number - 1)
	{
		tens = tens * 10;
	}

	number = pow * 10 - 1;
	i = -1;
	while (i++ < number)
	{
		if (ft_checkcomb(i, pow))
		{
			printf("%d ", i);
			//ft_putnbr(i);
		}
	}
}

int		main(void)
{
	ft_print_combn(2);
	return (0);
}
