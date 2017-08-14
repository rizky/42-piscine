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

char	*ft_strstr(char *str, char to_find)
{
	int i;
	int j;

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

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_atoi_base(char *str, char *base, int *sign)
{
	int		number;
	int		i;

	i = 0;
	number = 0;
	*sign = 1;
	while (str[i] <= ' ' || str[i] == '+')
			i++;
	if (str[i + 1] == '-')
	{
		*sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_strstr(base, str[i]))
			number = (number * ft_strlen(base)) + ft_strstr(base, str[i]) - base;
		else
			break ;
		i++;
	}
	return (number);
}

void	ft_itoa_base(int number, char *base, int *count, char **res, int sign)
{
	if (number / ft_strlen(base) > 0)
	{
		*count = *count + 1;
		ft_itoa_base(number / ft_strlen(base), base, count, res, sign);
	}
	else
	{
		*count = *count + 1;
		if(sign < 0)
			*count = *count + 1;
		*res = (char*)malloc(sizeof(char) * (*count + 1));
	}
	*count = *count - 1;
	(*res)[*count] = base[number % ft_strlen(base)];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	*res;
	int		count;
	int		sign;

	dec = ft_atoi_base(nbr, base_from, &sign);
	count = 0;
	ft_itoa_base(dec, base_to, &count, &res, sign);
	if(sign < 0)
		res[0] = '-';
	return (res);
}
