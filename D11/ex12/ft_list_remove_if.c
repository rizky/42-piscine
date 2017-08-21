/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:42:46 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:42:46 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list;
	t_list	*list_after;
	t_list	*list_before;

	list = *begin_list;
	list_before = *begin_list;
	while (list)
	{
		if ((*cmp)(list->data, data_ref) == 0)
		{
			list_after = list->next;
			free(list);
			if ((list_before == *begin_list) && (list_before->next == NULL))
				*begin_list = NULL;
			if ((list_before == *begin_list) && (list_after!=NULL))
				*begin_list = list_after;
			else
				list_before->next = list_after;
		}
		list_before = list;
		list = list->next;
	}
}
