#include "ft.h"
#include "ft_btree.h"

void ft_build_eval_tree(t_btree **root)
{
	char		**input;
	t_btree		*left_node;
	t_btree		*right_node;

	if(*root)
	{
		input = ft_split_once((*root)->item, "+");
		if (input[1])
		{
			left_node = btree_create_node(input[0]);
			(*root)->left = left_node;
			right_node = btree_create_node(input[1]);
			(*root)->right = right_node;
			ft_build_eval_tree(&(*root)->right);
			ft_build_eval_tree(&(*root)->left);
			(*root)->item = ft_strdup("+");
		}
		else
		{
			input = ft_split_once((*root)->item, "*");
			if (input[1])
			{
				left_node = btree_create_node(input[0]);
				(*root)->left = left_node;
				right_node = btree_create_node(input[1]);
				(*root)->right = right_node;
				ft_build_eval_tree(&(*root)->right);
				ft_build_eval_tree(&(*root)->left);
				(*root)->item = ft_strdup("*");
			}
		}
	}
}

int eval_expr(char *argv)
{
	char 	**input;
	t_btree		*root;

	root = btree_create_node(argv);
	ft_build_eval_tree(&root);

	btree_apply_suffix(root, &ft_putstr);
	ft_putstr("\n");
	btree_apply_prefix(root, &ft_putstr);
	ft_putstr("\n");
	btree_apply_infix(root, &ft_putstr);
	ft_putstr("\n");
	ft_putstr("\n");
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1) 
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0); 
}