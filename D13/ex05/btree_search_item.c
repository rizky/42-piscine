/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:13:11 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/22 17:13:12 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
	void *data_ref, int (*cmpf)(void *, void *))
{
	t_btree *result;

	if (!(root))
		return (0);
	result = btree_search_item(root->left, data_ref, cmpf);
	if (!result)
		if ((*cmpf)(data_ref, root->item) == 0)
			return (root);
	if (!result)
		result = btree_search_item(root->right, data_ref, cmpf);
	return (result);
}
