/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:01:51 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/09 09:01:52 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
			return (str + i);
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
	char	s[2];

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

int		ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		number;
	int		i;
	char	s[2];

	i = 0;
	sign = 1;
	number = 0;
	if (ft_isvalid(base))
	{
		while (str[i] <= ' ' || str[i] == '+')
			i++;
		if (str[i++] == '-')
			sign = -1;
		while (str[i++] != '\0')
		{
			s[0] = str[i - 1];
			s[1] = '\0';
			if (ft_strstr(base, s))
				number = (number * ft_strlen(base)) + ft_strstr(base, s) - base;
			else
				break ;
		}
	}
	return (number * sign);
}
