/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:26:23 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/04 14:33:41 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_iterative_power.c"

int main()
{
	printf("%d\n",ft_iterative_power(-2,-5));
	printf("%d\n",ft_iterative_power(-2,-10));
	printf("%d\n",ft_iterative_power(-2,-20));
	printf("%d\n",ft_iterative_power(2,30));
	printf("%d\n",ft_iterative_power(5,2));
	printf("%d\n",ft_iterative_power(5,10));
	printf("%d\n",ft_iterative_power(5,100));
}
