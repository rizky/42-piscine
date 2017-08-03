/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:12:27 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/02 23:59:11 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_reverse_alphabet(void)
{
	char i;
	char n;

	i = 'z';
	n = 'a';
	while (i >= n)
	{
		ft_putchar(i);
		i = i - 1;
	}
}

int		main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}
