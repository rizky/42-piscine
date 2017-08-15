/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:12:02 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/15 15:12:03 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_opp.h>

int		ft_add(int a, int b)
{
	return (a + b);
}

int		ft_sub(int a, int b)
{
	return (a - b);
}

int		ft_div(int a, int b)
{
	return (a / b);
}

int		ft_mod(int a, int b)
{
	return (a % b);
}

int		ft_mul(int a, int b)
{
	return (a * b);
}

void	ft_usage()
{
	ft_putstr("error : only [ - + * / % ] are accepted.");
}
