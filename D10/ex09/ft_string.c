/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:11:47 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/15 15:11:48 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	char *c;

	c = str;
	while (*c != '\0')
	{
		ft_putchar(*c);
		c++;
	}
}

int		ft_atoi(char *str)
{
	char	*c;
	int		sign;
	int		number;

	c = str;
	sign = 1;
	number = 0;
	while (*c == ' ' || *c == '\t' || *c == '\v' || *c == '+')
		c++;
	if (*c == '-')
	{
		sign = -1;
		c++;
	}
	while (*c != '\0')
	{
		if (*c >= '0' && *c <= '9')
			number = (number * 10) + (*c - '0');
		else
			break ;
		c++;
	}
	return (number * sign);
}

void	ft_putnbr(int nb)
{
	const char *base = "0123456789";

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if ((nb / 10) > 0)
		ft_putnbr(nb / 10);
	ft_putchar(base[nb % 10]);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
