/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 15:32:23 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 16:39:56 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*comb;
	int		i;
	int		j;

	comb = (char*)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	i = 0;
	while (dest[i])
	{
		comb[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j])
	{
		comb[i] = src[j];
		i++;
		j++;
	}
	comb[ft_strlen(dest) + ft_strlen(src)] = '\0';
	return (comb);
}
