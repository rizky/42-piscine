/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:39:51 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:40:03 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list_ptr;

	list_ptr = (t_list *)malloc(sizeof(t_list));
	if (list_ptr)
	{
		list_ptr->data = data;
		list_ptr->next = NULL;
	}
	return (list_ptr);
}
