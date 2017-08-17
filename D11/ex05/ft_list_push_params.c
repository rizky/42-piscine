/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:41:38 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:41:39 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int i;
	t_list *list;

	if(ac == 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		ft_list_push_front(&list, av[i]);
		i++;
	}
	return (list);
}
