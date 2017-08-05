/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 10:10:41 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 10:32:19 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int lower;
	int upper;
	int mid;

	upper = nb;
	lower = 0;
	while ((upper - lower) > 1)
	{
		mid = (((upper - lower) / 2) + lower);
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid > nb)
			upper = mid;
		else
			lower = mid;
	}
	return (0);
}

int		ft_is_prime(int nb)
{
	int isprime;
	int i;

	isprime = 1;
	if (nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	if (ft_sqrt(nb) != 0)
		return (0);
	i = 3;
	while (i < nb)
	{
		if (nb % i == 0)
			isprime = 0;
		i = i + 2;
	}
	return (isprime);
}

int		ft_find_next_prime(int nb)
{
	int i;
	int isprime;

	if (nb < 3)
		return (2);
	isprime = 0;
	i = nb;
	if (i % 2 == 0)
		i++;
	i = i - 2;
	while (isprime == 0)
	{
		i = i + 2;
		isprime = ft_is_prime(i);
	}
	return (i);
}
