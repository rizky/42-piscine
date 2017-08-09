/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:34:21 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/09 01:39:45 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	char	*c;
	int		len;

	len = 0;
	c = str;
	while (*c != '\0')
	{
		c++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(src);
	i = 0;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	while(src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
