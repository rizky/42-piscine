#include "ft.h"
#include "ft_btree.h"

char	*ft_unparented(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '(' || str[i] == ' '))
			break ;
		if (str[i] == '(')
		{
			j = ft_strlen(str) - 1;
			while (j > 0)
			{
				if (!(str[j] == ')' || str[j] == ' '))
					break ;
				if (str[j] == ')')
				{
					str[i] = ' ';
					str[j] = ' ';
					break ;
				}
				j--;
			}
			break ;
		}
		i++;
	}
	return (str);
}

int		ft_build_eval_tree(t_btree **root, char *op)
{
	char **input;

	if (*root)
	{
		input = ft_split_once((*root)->item, op);
		if (input[1])
		{
			(*root)->left = btree_create_node(ft_unparented(input[0]));
			(*root)->right = btree_create_node(ft_unparented(input[1]));
			(*root)->item = ft_strdup(op);
			ft_build_eval_tree(&(*root)->right, "+");
			ft_build_eval_tree(&(*root)->left, "+");
			ft_build_eval_tree(&(*root)->right, "-");
			ft_build_eval_tree(&(*root)->left, "-");
			ft_build_eval_tree(&(*root)->right, "/");
			ft_build_eval_tree(&(*root)->left, "/");
			ft_build_eval_tree(&(*root)->right, "*");
			ft_build_eval_tree(&(*root)->left, "*");
			ft_build_eval_tree(&(*root)->right, "%");
			ft_build_eval_tree(&(*root)->left, "%");
		}
		else
			return (0);
	}
	return (1);
}

int		eval_expr(char *argv)
{
	t_btree		*root;

	root = btree_create_node(ft_unparented(argv));
	if (ft_build_eval_tree(&root, "+"))
		return (btree_evaluate_prefix(root));
	else if (ft_build_eval_tree(&root, "-"))
		return (btree_evaluate_prefix(root));
	else if (ft_build_eval_tree(&root, "/"))
		return (btree_evaluate_prefix(root));
	else if (ft_build_eval_tree(&root, "*"))
		return (btree_evaluate_prefix(root));
	else if (ft_build_eval_tree(&root, "%"))
		return (btree_evaluate_prefix(root));
	btree_apply_prefix(root, &ft_putstr);
	ft_putstr("\n");
	return (0);
}
