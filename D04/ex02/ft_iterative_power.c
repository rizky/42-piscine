/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:19:08 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 12:38:23 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int res;
	int i;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		i = 0;
		res = 1;
		while (i < power)
		{
			res = res * nb;
			i++;
		}
		return (res);
	}
}
