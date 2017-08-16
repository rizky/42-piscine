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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*list;
	t_list	*list2;
	t_list	*tmp;

	list = *begin_list1;
	list2 = begin_list2;
	if (list)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while ((*cmp)(list->data, begin_list2->data) <= 0 && list->next)
	{
		list = list->next;
	}
	while (list2)
	{
		tmp = list->next;
		list->next = list2;
		list = list->next;
		list->next = tmp;
	}
}
