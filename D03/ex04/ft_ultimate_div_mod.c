/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:47:50 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 16:53:52 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "ft_putnbr.c"

void	ft_ultimate_div_mod(int *a, int *b)
{
	int div;
	int mod;

	div = *a / *b;
	mod = *a % *b;

	*a = div;
	*b = mod;
}

int		main(void)
{
	int a;
	int b;

	a = 13;
	b = 5;

	ft_ultimate_div_mod(&a, &b);

	ft_putnbr(a);
	ft_putnbr(b);
	return (0);
}
