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

void	ft_list_push_front05(t_list **begin_list, void *data)
{
	t_list	*list_ptr;

	if (*begin_list)
	{
		list_ptr = ft_create_elem(data);
		if (list_ptr)
		{
			list_ptr->next = (*begin_list);
			(*begin_list) = list_ptr;
		}
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list_ptr;

	list_ptr = 0;
	if (ac == 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		ft_list_push_front05(&list_ptr, av[i]);
		i++;
	}
	return (list_ptr);
}
