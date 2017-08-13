/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:32:39 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/11 15:32:40 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = dest;
	while (*ptr1)
		ptr1++;
	ptr2 = src;
	while (*ptr2)
	{
		*ptr1 = *ptr2;
		ptr2++;
		ptr1++;
	}
	*ptr1 = '\0';
	return (dest);
}

char	*ft_join(char **tab, char *sep)
{
	char	*str;
	int		len;
	int		i;

	i = 1;
	len = 0;
	while (tab[i])
	{
		len = len + ft_strlen(tab[i]);
		i++;
	}
	str = (char*)malloc(sizeof(*str) * ((len + 1) + (i * ft_strlen(sep))));
	i = 0;
	while (tab[i])
	{
		if (i != 0)
			str = ft_strcat(str, sep);
		str = ft_strcat(str, tab[i]);
		i++;
	}
	return (str);
}
