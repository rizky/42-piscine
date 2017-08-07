#include <stdio.h>
#include "ft_putnbr_base.c"

int main()
{
	int		nb20 = 456;
	char	base[100] = "102";
	int		min_int = -2147483648;
	ft_putnbr_base(214783647, "0123456789");
	printf("\n");	
	ft_putnbr_base(4, "01");
	printf("\n");
	ft_putnbr_base(nb20, "ABCD");
	printf("\n");
	ft_putnbr_base(-nb20, "ABCD");
	printf("\n");
	ft_putnbr_base(nb20, "abcde");
	printf("\n");
	ft_putnbr_base(nb20, "qwerty");
	printf("\n");
	ft_putnbr_base(nb20, "abc+te");
	printf("\n");
	ft_putnbr_base(nb20, "012345678-");
	printf("\n");
	ft_putnbr_base(nb20, "abc+te");
	printf("\n");
	ft_putnbr_base(nb20, "abcee");

	return (0);
}
