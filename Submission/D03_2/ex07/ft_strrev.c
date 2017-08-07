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

#include <unistd.h>

char	*ft_strrev(char *str)
{
	char	*c;
	char	*rev;
	char	temp;

	rev = str;
	while (*rev != '\0')
	{
		rev++;
	}
	rev--;
	c = str;
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
