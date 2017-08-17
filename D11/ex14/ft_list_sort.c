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
#include <stdio.h>

void				ft_print_list_str(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current_list;
	t_list	*prev_list;

	current_list = *begin_list;
	prev_list = current_list;
	while (current_list->next)
	{
		if(cmp(current_list->data, current_list->next->data) > 0)
		{
			if(current_list == *begin_list)
			{
				*begin_list = current_list->next;
				current_list->next = current_list->next->next;
				(*begin_list)->next = current_list;
			}
			else
			{
				prev_list->next = current_list->next;
				current_list->next = current_list->next->next;
				prev_list->next->next = current_list;
			}
			current_list = *begin_list;
		}
		else
		{
			prev_list = current_list;
			current_list = current_list->next;
		}
	}
}
