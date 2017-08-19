/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:43:28 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:43:28 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list *ft_create_elem17(void *data)
{
	t_list *list_ptr;

	list_ptr = (t_list *)malloc(sizeof(t_list));
	if (list_ptr)
	{
		list_ptr->data = data;
		list_ptr->next = NULL;
	}
	return (list_ptr);
}

void	ft_sorted_list_insert17(t_list **begin_list, void *data, int (*cmp)(char *, char *))
{
	t_list	*list;
	t_list	*prev_list;

	list = *begin_list;
	if (!list)
	{
		*begin_list = ft_create_elem17(data);
		return ;
	}
	prev_list = *begin_list;
	while (list)
	{
		if(cmp(list->data, data) > 0)
			break ;
		prev_list = list;
		list = list->next;
	}
	if(prev_list == *begin_list)
	{
		*begin_list = ft_create_elem17(data);
		(*begin_list)->next = list;
	}
	else
	{
		prev_list->next = ft_create_elem17(data);
		prev_list->next->next = list;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*list;
	t_list	*list2;

	list = *begin_list1;
	list2 = begin_list2;
	if (!list)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (list2)
	{
		ft_sorted_list_insert17(begin_list1, list2->data, cmp);
		list2 = list2->next;
	}
}
