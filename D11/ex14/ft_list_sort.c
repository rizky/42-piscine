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
	t_list	*current_list;
	t_list	*prev_list;

	current_list = *begin_list;
	prev_list = *begin_list;
	while (current_list)
	{
		if(cmp(current_list->data, current_list->next->data) < 0)
		{
			prev_list->next = current_list->next;
			current_list->next = current_list->next->next;
			prev_list->next->next = current_list;
			current_list = *begin_list;
		}
		prev_list = current_list;
		current_list = current_list->next;
	}
}
