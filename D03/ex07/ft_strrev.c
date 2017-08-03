/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 17:14:44 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/03 18:17:50 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "ft_putstr.c"

char		*ft_strrev(char *str)
{
	char *c;
	char *rev;
	char temp;

	rev = str;
	while (*rev != '\0')
	{
		rev++;
	}
	rev--;
	c = str;
	int i = 0;
	while (rev > c)
	{
		temp = *c;
		*c = *rev;
		*rev = temp;
		c++;
		rev--;
		i++;
	}
	return (str);
}

int		main(void)
{
	char str[]="fab0cdef";
	
	ft_putstr(ft_strrev(str));
	return (0);
}
