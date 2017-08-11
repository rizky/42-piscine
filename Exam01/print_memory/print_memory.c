#include <unistd.h>

void		ft_print_hex(int octet, int reminder)
{
	const char *base = "0123456789abcdef";

	if(reminder > 1)
		ft_print_hex(octet /  16, reminder - 1);
	write(1, base + octet % 16, 1);
}

void		ft_print_bin(int octet, int reminder)
{
	const char *base = "0123456789abcdef";

	if(reminder > 1)
		ft_print_bin(octet /  2, reminder - 1);
	write(1, base + octet % 2, 1);
}