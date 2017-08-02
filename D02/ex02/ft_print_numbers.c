/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:14:42 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/02 10:19:27 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

void ft_print_numbers()
{
    char i = '0';
    char n = '9';

    while (i <= n)
    {
		ft_putchar(i);
		i = i + 1;
    }
}

int main()
{
    ft_print_numbers();
    return 0;
}
