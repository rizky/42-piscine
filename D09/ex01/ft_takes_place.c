/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:07:25 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/10 18:40:42 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	if (hour == 24)
		hour = 0;
	if (hour >= 0 && hour < 11)
	{
		if (hour == 0)
			printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M AND %d.00 A.M.\n", 12, 1);
		else
			printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M AND %d.00 A.M.\n", hour, hour + 1);
	}
	else if (hour == 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M AND %d.00 P.M.\n", hour, hour + 1);
	else if (hour >= 12 && hour < 23)
	{
		if (hour == 12)
			printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M AND %d.00 P.M.\n", 12, 1);
		else
			printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M AND %d.00 P.M.\n", hour - 12, hour - 12 + 1);
	}
	else if (hour == 23)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M AND %d.00 A.M.\n", hour - 12, hour -12 + 1);
}
