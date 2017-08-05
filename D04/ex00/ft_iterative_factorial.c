/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:25:38 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 10:56:40 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int fact;
	int sign;

	fact = 1;
	i = 1;
	sign = 1;
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
		fact = 1;
	else if (nb > 12)
		fact = 0;
	else
		while (++i <= nb)
			fact = fact * i;
	return (fact * sign);
}
