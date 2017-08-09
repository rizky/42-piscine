/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:51:30 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 20:27:05 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
