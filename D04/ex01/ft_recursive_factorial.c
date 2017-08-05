/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:49:14 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 12:35:45 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 12)
		return (0);
	if (nb < 0)
		return (0);
	if (nb > 0)
		return (nb * ft_recursive_factorial(nb - 1));
	else if (nb < 0)
		return (nb * ft_recursive_factorial(nb + 1));
	else
		return (1);
}
