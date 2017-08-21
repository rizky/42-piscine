#include <stddef.h>
#include "ft.h"

void	ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet / 16, rem - 1);
	write(1, base + (octet % 16), 1);
}

void	sp_putchar(unsigned char const *ptr)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);
}

void	ft_print_space(int isC)
{
	ft_putchar(' ');
	if (isC)
		ft_putchar(' ');
}

void	ft_print_space_hex(int a, int isC)
{
	if (a == 7 && isC)
		ft_putchar(' ');
	if (a < 15)
		ft_putchar(' ');
}

void	ft_print_memory(const void *addr, size_t size, int isC)
{
	size_t i;
	size_t a;
	unsigned char const *ptr = addr;

	i = 0;
	while (i < size)
	{
		a = 0;
		ft_putnbr_hex(i, 7 + isC);
		ft_print_space(isC);
		while (a < 16 && a + i < size)
		{
			ft_putnbr_hex(*(ptr + i + a), 2);
			ft_print_space_hex(a, isC);
			a++;
		}
		while (a < 16)
		{
			ft_putstr("  ");
			ft_print_space_hex(a, isC);
			a++;
		}
		if (isC)
		{
			a = 0;
			ft_print_space(isC);
			ft_putchar('|');
			while (a < 16 && a + i < size)
			{
				sp_putchar(ptr + a + i);
				a++;
			}
			ft_putchar('|');
		}
		ft_putchar('\n');
		i += 16;
	}
	ft_putnbr_hex(size, 7 + isC);
	ft_putchar('\n');
}
