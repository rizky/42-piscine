/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 17:06:37 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 17:10:28 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "ft_putnbr.c"
int		ft_strlen(char *str)
{
	char *c;
	int len;

	len = 0;
	c = str;
	while (*c != '\0')
	{
		c++;
		len++;
	}
	return (len);
}

int		main(void)
{
	char *str;
	
	str = "Hello";
	ft_putnbr(ft_strlen(str));
	return (0);
}
