/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 17:40:35 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 21:30:15 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j])
		{
			if (str[i + j] == to_find[j])
				j++;
			else
				break ;
		}
		if (to_find[j] == '\0')
			return (str+i);
		i++;
	}
	return (NULL);
}

int		ft_strlen(char *str)
{
	char	*c;
	int		len;

	c = str;
	len = 0;
	while (*c)
	{
		len++;
		c++;
	}
	return (len);
}

int		ft_isvalid(char *base)
{
	int		i;
	char	*plus;
	char	*minus;
	char	*duplicate;
	char	s[1];

	plus = ft_strstr(base, "+");
	minus = ft_strstr(base, "-");
	i = 0;
	while (i < ft_strlen(base))
	{
		s[0] = base[i];
		duplicate = ft_strstr(base, s);
		if (duplicate == &base[i])
			duplicate = NULL;
		else
			break ;
		i++;
	}
	if (plus == NULL && minus == NULL && duplicate == NULL)
		i = 1;
	else
		i = 0;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			ibase;
	int			sign;
	long long	long_nbr;

	long_nbr = nbr;
	if (ft_isvalid(base))
	{
		ibase = ft_strlen(base);
		sign = 1;
		if (nbr < 0)
		{
			ft_putchar('-');
			sign = -1;
			long_nbr = sign * long_nbr;
		}
		if (long_nbr > 0)
		{
			ft_putnbr_base(long_nbr / ibase, base);
			ft_putchar(base[(long_nbr % ibase)]);
		}
	}
}
