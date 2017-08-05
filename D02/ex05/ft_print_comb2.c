/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:47:42 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 01:16:08 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_comb2(void)
{
	int i[2];

	i[0] = -1;
	while (i[0]++ < 99)
	{
		i[1] = -1;
		while (i[1]++ < 99)
		{
			if (i[0] < i[1])
			{
				if (!(i[0] == 0 && i[1] == 1))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				ft_putchar(i[0] / 10 + '0');
				ft_putchar(i[0] % 10 + '0');
				ft_putchar(' ');
				ft_putchar(i[1] / 10 + '0');
				ft_putchar(i[1] % 10 + '0');
			}
		}
	}
}

int		main(void)
{
	ft_print_comb2();
	return (0);
}
