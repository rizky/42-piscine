/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:40:59 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:41:00 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list_ptr;

	if (*begin_list)
	{
		list_ptr = ft_create_elem(data);
		if(list_ptr)
		{
			list_ptr->next = (*begin_list);
			(*begin_list) = list_ptr;
		}
	}
	else
		*begin_list = ft_create_elem(data);
}