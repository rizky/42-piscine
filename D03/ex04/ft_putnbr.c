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