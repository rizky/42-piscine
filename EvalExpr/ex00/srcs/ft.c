/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 22:12:52 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/20 22:12:57 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		ft_putchar((char)n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int		ft_atoi(char *str)
{
	int	ret;
	int	sign;

	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
		str++;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	ret = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	return (ret * sign);
}

int		ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
			l++;
		str++;
	}
	return (l);
}

char	*ft_remove_whitespaces(char *str)
{
	char	*ret;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str);
	ret = (char*)malloc(sizeof(char) * (size + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			ret[j++] = str[i++];
		else
			i++;
	}
	ret[j] = '\0';
	return (ret);
}
