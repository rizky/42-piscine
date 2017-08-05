/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:26:23 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/04 14:42:06 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_recursive_power.c"

int main()
{
	printf("%d\n",ft_recursive_power(2,5));
	printf("%d\n",ft_recursive_power(2,10));
	printf("%d\n",ft_recursive_power(2,100));
	printf("%d\n",ft_recursive_power(5,2));
	printf("%d\n",ft_recursive_power(5,20));
	printf("%d\n",ft_recursive_power(5,100));
}
