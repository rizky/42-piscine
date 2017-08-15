/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:11:14 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/15 15:11:17 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_opp.h"

int	ft_operate(int a, int b, int (*f)(int, int))
{
	return (f(a, b));
}

int	ft_execute(int a, int b, char op)
{
	int (*f)(int, int);

	if (ft_strcmp(op, "+") == 0)
		f = &ft_plus;
	else if (ft_strcmp(op, "-") == 0)
		f = &ft_minus;
	else if (ft_strcmp(op, "/") == 0)
		f = &ft_div;
	else if (ft_strcmp(op, "%") == 0)
		f = &ft_mod;
	else if (ft_strcmp(op, "*") == 0)
		f = &ft_mul;
	else
		return (0);
	ft_putnbr(ft_operate(a, b, f));
	return (0);
}

int	main(int argc, char **argv)
{
	int a;
	int b;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if (b == 0 && (ft_strcmp(argv[2], "/") == 0))
		{
			ft_putstr("Stop : division by zero");
			return (0);
		}
		if (b == 0 && (ft_strcmp(argv[2], "%") == 0))
		{
			ft_putstr("Stop : module by zero");
			return (0);
		}
		ft_execute(a, b, argv[2]);
	}
	return (0);
}
