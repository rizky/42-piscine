/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:43:07 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:43:08 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*front_list;
	t_list	*back_list;
	t_list	*ptr_list;
	void	*data;

	front_list = begin_list;
	ptr_list = begin_list;
	if (!ptr_list)
		return ;
	while (ptr_list->next)
		ptr_list = ptr_list->next;
	back_list = ptr_list;
	while (front_list != back_list && back_list->next != front_list)
	{
		data = front_list->data;
		front_list->data = back_list->data;
		back_list->data = data;
		front_list = front_list->next;
		ptr_list = begin_list;
		while (ptr_list->next != back_list)
			ptr_list = ptr_list->next;
		back_list = ptr_list;
	}
}
