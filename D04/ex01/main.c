/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:14:32 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 10:54:47 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_recursive_factorial.c"

int main(void)
{
	printf("%d\n", ft_recursive_factorial(0));
	printf("%d\n", ft_recursive_factorial(1));
	printf("%d\n", ft_recursive_factorial(2));
	printf("%d\n", ft_recursive_factorial(5));
	printf("%d\n", ft_recursive_factorial(5));
	printf("%d\n", ft_recursive_factorial(12));
	printf("%d\n", ft_recursive_factorial(13));
	printf("%d\n", ft_recursive_factorial(-5));
	printf("%d\n", ft_recursive_factorial(-6));
	printf("%d\n", ft_recursive_factorial(-7));
	printf("%d\n", ft_recursive_factorial(-8));
	printf("%d\n", ft_recursive_factorial(-9));
	printf("%d\n", ft_recursive_factorial(-10));
	printf("%d\n", ft_recursive_factorial(-11));
	printf("%d\n", ft_recursive_factorial(-12));

	return (0);
}
