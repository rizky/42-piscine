/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 11:56:24 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 00:22:20 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_comb(void)
{
	char i[3];

	i[0] = '/';
	while (i[0]++ < '9')
	{
		i[1] = '/';
		while (i[1]++ < '9')
		{
			i[2] = '/';
			while (i[2]++ < '9')
			{
				if (i[0] < i[1] && i[1] < i[2])
				{
					if (!(i[0] == '0' && i[1] == '1' && i[2] == '2'))
					{
						ft_putchar(',');
						ft_putchar(' ');
					}
					ft_putchar(i[0]);
					ft_putchar(i[1]);
					ft_putchar(i[2]);
				}
			}
		}
	}
}

int		main(void)
{
	ft_print_comb();
	return (0);
}
