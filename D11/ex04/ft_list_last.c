/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:41:29 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:41:30 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	if (list_ptr)
	{
		while (list_ptr->next)
		{
			list_ptr = list_ptr->next;
		}
		return (list_ptr);
	}
	return (list_ptr);
}
