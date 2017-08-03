/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:14:42 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 00:09:22 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_numbers(void)
{
	char i;
	char n;

	i = '0';
	n = '9';
	while (i <= n)
	{
		ft_putchar(i);
		i = i + 1;
	}
}

int		main(void)
{
	ft_print_numbers();
	return (0);
}
