/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:22:42 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 18:32:36 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	char 	*c;
	int		sign;
	int		number;

	c = str;
	sign = 1;
	number = 0;
	while (*c == ' ' || *c == '\t' || *c == '\v')
		c++;
	if (*c == '-')
	{
		sign = -1;
		c++;
	}
	else if (*c == '+')
	{
		sign = 1;
		c++;
	}
	while (*c != '\0')
	{
		if (*c >= '0' && *c <= '9')
		{
			number = (number * 10) + (*c - '0');
		}
		else
			break ;
		c++;
	}
	return (number * sign);
}
