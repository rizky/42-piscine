/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 14:49:03 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 14:49:04 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			res = 0;
			break ;
		}
		i++;
	}
	return (res);
}
