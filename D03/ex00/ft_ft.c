/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 12:35:06 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 15:46:49 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "ft_putnbr.c"

void	ft_ft(int *nbr)
{
	if (nbr)
		*nbr = 42;
}

int		main(void)
{
	int a;
	int *ptr;
	a = 0;

	ft_ft(&a);
	
	ft_putnbr(a);
	return (0);
}
