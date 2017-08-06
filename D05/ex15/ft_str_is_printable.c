/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 14:54:54 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 14:54:55 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < ' ')
		{
			res = 0;
			break ;
		}
		i++;
	}
	return (res);
}
