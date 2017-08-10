/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:53:01 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/10 20:53:03 by rnugroho         ###   ########.fr       */
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

char	*ft_rot42(char *str)
{
	char	*rot42;
	char	alpha_upper[26] = "PQRSTUVWXYZABCDEFGHIJKLMNO";
	char	alpha_lower[26] = "pqrstuvwxyzabcdefghijklmno";
	int		i;
	
	rot42 = (char*)malloc(sizeof(*rot42) * (ft_strlen(str) + 1));

	i = 0;
	while(str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			rot42[i] = alpha_upper[str[i] - 'A'];
		else if(str[i] >= 'a' && str[i] <= 'z')
			rot42[i] = alpha_lower[str[i] - 'a'];
		else
			rot42[i] = str[i];
		i++;
	}
	return (rot42);
}