/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:59:55 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/11 15:59:57 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "ft_perso.h"

#define IS_DIGIT(x) (x >= '0' && x <= '9')
#define IS_SPACE(x) (x==' '||x =='\t'||x=='\n'||x=='\v'||x=='\f'||x=='\r')
#define IS_ALPHA(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))

char			*ft_strdup(char const *str, int n)
{
	char	*new_buf;
	int		i;

	new_buf = (char*)malloc(sizeof(char) * (n + 1));
	if (!new_buf)
		return (NULL);
	i = -1;
	while (str[++i] && i < n)
		new_buf[i] = str[i];
	return (new_buf);
}

int				ft_atoi(char *str)
{
	int i;
	int result;
	int neg;

	i = 0;
	while (IS_SPACE(str[i]))
		++i;
	neg = 0;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = 1;
	if (IS_DIGIT(str[i]))
	{
		result = str[i++] - '0';
		while (IS_DIGIT(str[i]))
			result = (result * 10) + (str[i++] - '0');
		if (neg)
			result = -result;
	}
	return (result);
}

t_perso			*next_perso(char *str, int *i)
{
	int		j;
	int		state;
	t_perso	*perso;

	j = 0;
	state = 0;
	perso = (t_perso*)malloc(sizeof(t_perso));
	while (str[++(*i)])
	{
		if (!state && IS_DIGIT(str[*i]))
		{
			j = *i;
			state = 1;
		}
		else if (state == 1 && str[*i] == '|')
		{
			perso->age = ft_atoi(str + j);
			state = 2;
			j = *i + 1;
		}
		else if (state == 2 && str[*i] == ';')
			break ;
	}
	perso->name = ft_strdup(str + j, *i - j);
	return (perso);
}

t_perso			**ft_decrypt(char *str)
{
	t_perso	**array;
	int		index;
	int		i;

	index = -1;
	i = -1;
	array = (t_perso**)malloc(sizeof(t_perso*) * 4);
	array[3] = (NULL);
	while (array[++index])
	{
		array[index] = next_perso(str, &i);
		str += i;
		i = 0;
	}
	return (array);
}
