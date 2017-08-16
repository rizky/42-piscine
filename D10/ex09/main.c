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

#include "header.h"
#include "ft_opp.h"

int		ft_operate(int a, int b, int (*f)(int, int))
{
	return (f(a, b));
}

void	ft_execute(int a, int b, char *op)
{
	int		i;

	i = 0;
	while (g_opptab[i].op[0] && ft_strcmp(g_opptab[i].op, op))
		i++;
	if (g_opptab[i].op[0])
		ft_putnbr(g_opptab[i].func(a, b));
	else
		g_opptab[i].func(a, b);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if (b == 0 && (ft_strcmp(argv[2], "/") == 0))
		{
			ft_putstr("Stop : division by zero\n");
			return (0);
		}
		if (b == 0 && (ft_strcmp(argv[2], "%") == 0))
		{
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
		ft_execute(a, b, argv[2]);
	}
	return (0);
}
