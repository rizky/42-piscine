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

void	ft_insert_list17(t_list **begin_list,
	t_list *inserted_list, t_list **current_list, t_list **prev_list)
{
if ((*current_list) == *begin_list)
{
	*begin_list = inserted_list;
	(*begin_list)->next = *current_list;
}
else
{
	(*prev_list)->next = inserted_list;
	(*prev_list)->next->next = *current_list;
}
}

void	ft_sorted_list_insert17(t_list **begin_list,
			t_list *inserted_list, int (*cmp)(char *, char *))
{
	t_list	*list;
	t_list	*prev_list;

	list = *begin_list;
	if (!list)
	{
		*begin_list = inserted_list;
		return ;
	}
	prev_list = *begin_list;
	while (list)
	{
		if (cmp(list->data, inserted_list->data) > 0)
			break ;
		prev_list = list;
		list = list->next;
	}
	ft_insert_list17(begin_list, inserted_list, &list, &prev_list);
}

t_list	*ft_list_before_last17(t_list *begin_list)
{
	t_list	*list_ptr;
	t_list	*prev_list;

	list_ptr = begin_list;
	prev_list = begin_list;
	if (list_ptr)
	{
		while (list_ptr->next)
		{
			prev_list = list_ptr;
			list_ptr = list_ptr->next;
		}
		return (prev_list);
	}
	return (prev_list);
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	t_list	*list;
	t_list	*list2;

	list = *begin_list1;
	if (!list)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (begin_list2)
	{
		list2 = ft_list_before_last17(begin_list2);
		ft_sorted_list_insert17(begin_list1, list2->next, cmp);
		if (list2 == begin_list2)
		{
			ft_sorted_list_insert17(begin_list1, list2, cmp);
			begin_list2 = NULL;
		}
		else
			list2->next = NULL;
	}
}
