/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 01:18:30 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 02:11:12 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnbr(int number)
{
	int tens;

	if (number < 0)
	{
		ft_putchar('-');
		if (number <= -2147483648)
		{
			ft_putchar('2');
			number = -147483648;
		}
		number = number * -1;
	}
	tens = 1;
	while (tens <= number / 10)
		tens = tens * 10;
	while (tens > 0)
	{
		ft_putchar(number / tens + '0');
		number = number % tens;
		tens = tens / 10;
	}
}

int		main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}
