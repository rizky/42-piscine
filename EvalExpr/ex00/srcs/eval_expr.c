/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 22:12:43 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/20 22:12:44 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"
#include "ft.h"
#include <stdlib.h>

int	ft_eval_orde_2(char **str)
{
	int		result;
	char	*s;

	s = *str;
	result = 0;
	if (*s == '(')
	{
		s++;
		result = ft_eval_orde_0(&s);
		s++;
	}
	else
	{
		while (('0' <= *s) && (*s <= '9'))
		{
			result = result * 10 + *s - '0';
			s++;
		}
	}
	*str = s;
	return (result);
}

int	ft_eval_orde_1(char **str)
{
	int		result;
	char	*s;

	s = *str;
	result = ft_eval_orde_2(&s);
	while ((*s == '*') || (*s == '/') || (*s == '%'))
	{
		if (*s == '*')
		{
			s++;
			result *= ft_eval_orde_2(&s);
		}
		else if (*s == '/')
		{
			s++;
			result /= ft_eval_orde_2(&s);
		}
		else if (*s == '%')
		{
			s++;
			result %= ft_eval_orde_2(&s);
		}
	}
	*str = s;
	return (result);
}

int	ft_eval_orde_0(char **str)
{
	int		result;
	char	*s;

	s = *str;
	result = ft_eval_orde_1(&s);
	while ((*s == '+') || (*s == '-'))
	{
		if (*s == '+')
		{
			s++;
			result += ft_eval_orde_1(&s);
		}
		else if (*s == '-')
		{
			s++;
			result -= ft_eval_orde_1(&s);
		}
	}
	*str = s;
	return (result);
}

int	eval_expr(char *str)
{
	int		result;

	str = ft_remove_whitespaces(str);
	result = ft_eval_orde_0(&str);
	return (result);
}
