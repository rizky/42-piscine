/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:12:27 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/02 10:13:54 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

void ft_print_reverse_alphabet()
{
	char i = 'z';
	char n = 'a';

	while (i >= n)
	{
		ft_putchar(i);
		i = i - 1;
	}
}

int main()
{
	ft_print_reverse_alphabet();
	return 0;
}
