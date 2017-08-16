/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:43:01 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:43:02 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*before;
	t_list	*after;

	list = *begin_list;
	before = *begin_list;
	while (list->next)
	{
		if ((*cmp)(list->data, list->next->data) > 0)
		{
			tmp_a = list;
			tmp_b = list->next;
			after = tmp_b->next;
			before->next = tmp_b;
			tmp_b->next = tmp_a;
			tmp_a->next = after;
			list = tmp_b;
		}
		else
			list = list->next;
	}
}
