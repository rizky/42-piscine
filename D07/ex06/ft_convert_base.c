/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:45:18 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/14 15:45:22 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strch(char *str, char to_find)
{
	int i;

	if (to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}

int		ft_isvalid(char *base)
{
	int		i;
	char	*plus;
	char	*minus;
	char	*duplicate;
	int		len;

	len = 0;
	while (base[len])
		len++;
	plus = ft_strch(base, '+');
	minus = ft_strch(base, '-');
	i = 0;
	while (i < len)
	{
		duplicate = ft_strch(base, base[i]);
		if (duplicate == &base[i])
			duplicate = NULL;
		else
			break ;
		i++;
	}
	i = 0;
	if (plus == NULL && minus == NULL && duplicate == NULL)
		i = 1;
	return (i);
}

int		ft_atoi_base(char *str, char *base, int *sign)
{
	int		number;
	int		i;
	int		len;

	len = 0;
	while (base[len])
		len++;
	i = 0;
	number = 0;
	*sign = 1;
	while (str[i] <= ' ' || str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_strch(base, str[i]))
			number = (number * len) + ft_strch(base, str[i]) - base;
		i++;
	}
	return (number);
}

void	ft_itoa_base(int number, char *base, int *count, char **res)
{
	int		len;

	len = 0;
	while (base[len])
		len++;
	if (number / len > 0)
	{
		*count = *count + 1;
		ft_itoa_base(number / len, base, count, res);
	}
	else
	{
		*count = *count + 1;
		*res = (char*)malloc(sizeof(char) * (*count + 1));
	}
	*count = *count - 1;
	(*res)[*count] = base[number % len];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	*res;
	int		count;
	int		sign;

	if(!ft_isvalid(base_from) || !ft_isvalid(base_to))
		return NULL;
	dec = ft_atoi_base(nbr, base_from, &sign);
	count = 0;
	if (sign < 0)
		count = 1;
	ft_itoa_base(dec, base_to, &count, &res);
	if (sign < 0)
		res[0] = '-';
	return (res);
}
