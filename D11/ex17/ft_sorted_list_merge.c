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

void	ft_sorted_list_insert_list(t_list **begin_list, t_list	*tmp, int (*cmp)())
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		*begin_list = tmp;
		return ;
	}
	while ((*cmp)(list->data, tmp->data) <= 0 && list->next)
	{
		list = list->next;
	}
	tmp = list->next;
	list->next = tmp;
	list = list->next;
	list->next = tmp;
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
		ft_sorted_list_insert_list(begin_list1, list2, cmp);
	}
}
