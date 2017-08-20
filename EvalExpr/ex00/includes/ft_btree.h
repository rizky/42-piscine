#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)());
int 	ft_build_eval_tree(t_btree **root, char *op);
int		btree_evaluate_prefix(t_btree *root);
void	btree_insert_data(t_btree **root,
	void *item, int (*cmpf)(void *, void *));
#endif
