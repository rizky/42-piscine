/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:13:59 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/22 17:14:00 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		ft_max(int left, int right)
{
	if (left > right)
		return (left);
	else
		return (right);
}

int		btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_max(btree_level_count(root->left),
	btree_level_count(root->right)) + 1);
}

void	btree_apply_by_level2(t_btree *root, int current_level,
		int level,
		void (*applyf)(void *item, int current_level,
		int is_first_elem))
{
	if (!root)
		return ;
	if (level == current_level)
		(*applyf)(root->item, current_level, 0);
	else
	{
		btree_apply_by_level2(root->left, current_level + 1, level, applyf);
		btree_apply_by_level2(root->right, current_level + 1, level, applyf);
	}
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level,
			int is_first_elem))
{
	int i;
	int j;

	i = btree_level_count(root);
	j = 0;
	while (j < i)
	{
		btree_apply_by_level2(root, 0, j, applyf);
		j++;
	}
}
