/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:12:24 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/22 17:12:25 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*btree;

	btree = (t_btree*)malloc(sizeof(t_btree));
	if (btree)
	{
		btree->left = 0;
		btree->right = 0;
		btree->item = item;
	}
	return (btree);
}
