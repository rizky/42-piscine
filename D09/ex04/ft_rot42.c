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

void	ft_assign_upper(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 'P';
	while (c <= 'Z')
	{
		str[i] = c;
		c = c + 1;
		i++;
	}
	c = 'A';
	while (c <= 'O')
	{
		str[i] = c;
		c = c + 1;
		i++;
	}
}

void	ft_assign_lower(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 'p';
	while (c <= 'z')
	{
		str[i] = c;
		c = c + 1;
		i++;
	}
	c = 'a';
	while (c <= 'o')
	{
		str[i] = c;
		c = c + 1;
		i++;
	}
}

char	*ft_rot42(char *str)
{
	char	*rot42;
	char	alpha_upper[26];
	char	alpha_lower[26];
	int		i;

	ft_assign_upper(alpha_upper);
	ft_assign_lower(alpha_lower);
	rot42 = (char*)malloc(sizeof(*rot42) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			rot42[i] = alpha_upper[str[i] - 'A'];
		else if (str[i] >= 'a' && str[i] <= 'z')
			rot42[i] = alpha_lower[str[i] - 'a'];
		else
			rot42[i] = str[i];
		i++;
	}
	return (rot42);
}
