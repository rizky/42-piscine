/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:14:11 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 12:50:29 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_sqrt(int nb)
{
    int lower;
    int upper;
    int mid;

    upper = nb;
    lower = 0;
    while ((upper - lower) > 1)
    {
        if (upper - lower > 46340)
            upper = 46340;
        else
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
