/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:51:46 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/21 17:51:47 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"

void	ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet / 16, rem - 1);
	write(1, base + (octet % 16), 1);
}

void	ft_print_space(int is_c)
{
	ft_putchar(' ');
	if (is_c)
		ft_putchar(' ');
}

void	ft_print_space_hex(int a, int is_c)
{
	if (a == 7 && is_c)
		ft_putchar(' ');
	if (a < 15)
		ft_putchar(' ');
}

void	ft_print_all(size_t size, int is_c, int i, unsigned char const *ptr)
{
	size_t	a;

	a = 0;
	ft_putnbr_hex(i, 7 + is_c);
	ft_print_space(is_c);
	while (a < 16 && a + i < size)
	{
		ft_putnbr_hex(*(ptr + i + a), 2);
		ft_print_space_hex(a, is_c);
		a++;
	}
	while (a < 16)
	{
		ft_putstr("  ");
		ft_print_space_hex(a, is_c);
		a++;
	}
}

void	ft_print_memory(const void *addr, size_t size, int is_c)
{
	size_t				i;
	size_t				a;
	unsigned char const *ptr = addr;

	i = 0;
	while (i < size)
	{
		ft_print_all(size, is_c, i, ptr);
		if (is_c)
		{
			a = 0;
			ft_print_space(is_c);
			ft_putchar('|');
			while (a < 16 && a + i < size)
			{
				ft_putchar_mem(ptr + a + i);
				a++;
			}
			ft_putchar('|');
		}
		ft_putchar('\n');
		i += 16;
	}
	ft_putnbr_hex(size, 7 + is_c);
	ft_putchar('\n');
}
