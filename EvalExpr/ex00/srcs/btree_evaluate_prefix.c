/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 16:39:43 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/25 16:40:36 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft.h"

int btree_evaluate_prefix(t_btree *root)
{
	int x;
	int y;
	int z;
	int i;
	char *temp;
	char data;

	i = 0;
	data = '\0';
	temp = (char*)root->item;
	while (i < ft_strlen(temp))
	{
		if (temp[i] != ' ')
		{
			data = temp[i];
			break ;
		}
		i++;
	}

	z = 0;
	if (data == '+' || data == '-'|| data == '*'|| data == '/') {
		x = btree_evaluate_prefix(root->left);
		y = btree_evaluate_prefix(root->right);
		if (data=='+')
			z=x+y;
		else if (data=='-')
			z=x-y;
		else if (data=='*')
			z=x*y;
		else if (data=='/')
			z=x/y;
		return z;
	}
	else 
		return ft_atoi(temp);
}