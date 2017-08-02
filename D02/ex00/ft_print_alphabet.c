/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 09:25:58 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/02 10:09:36 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

void ft_print_alphabet()
{
	char i = 'a';
	char n = 'z';

	while (i <= n)
	{
		ft_putchar(i);
		i = i + 1;
	}
}

int main()
{
	ft_print_alphabet();
	return 0;
}
