/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:43:18 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:43:19 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*list;
	t_list	*tmp;

	list = *begin_list;
	if (list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while ((*cmp)(list->data, data) <= 0 && list->next)
	{
		list = list->next;
	}
	tmp = list->next;
	list->next = ft_create_elem(data);
	list = list->next;
	list->next = tmp;
}
