/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 14:51:41 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 14:51:43 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
		{
			res = 0;
			break ;
		}
		i++;
	}
	return (res);
}
