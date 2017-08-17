/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:41:16 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:41:19 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*list_ptr;
	int		i;

	i = 0;
	list_ptr = begin_list;
	while (list_ptr)
	{
		list_ptr = list_ptr->next;
		i++;
	}
	return (i);
}
