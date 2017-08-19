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

void	ft_insert_list(t_list **begin_list,
		void *data, t_list **current_list, t_list **prev_list)
{
	if ((*prev_list) == *begin_list)
	{
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = *current_list;
	}
	else
	{
		(*prev_list)->next = ft_create_elem(data);
		(*prev_list)->next->next = *current_list;
	}
}

void	ft_sorted_list_insert(t_list **begin_list,
		void *data, int (*cmp)(char *, char *))
{
	t_list	*list;
	t_list	*prev_list;

	list = *begin_list;
	if (!list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	prev_list = *begin_list;
	while (list)
	{
		if (cmp(list->data, data) > 0)
			break ;
		prev_list = list;
		list = list->next;
	}
	ft_insert_list(begin_list, data, &list, &prev_list);
}
