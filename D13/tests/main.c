#include "ft_btree.h"
#include <string.h>


void ft_putstr_w(void *data)
{
    ft_putstr((char*)data);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int ft_strcmp_w(void *s1, void *s2)
{
    return (ft_strcmp((char*) s1, (char*) s2));
}

int main()
{
    t_btree *root;
    t_btree *result;

    root = btree_create_node(strdup("b"));
    root->left = btree_create_node(strdup("a"));
    root->right = btree_create_node(strdup("c"));
    btree_apply_prefix(root, &ft_putstr_w);
    ft_putstr("\n");
    btree_apply_infix(root, &ft_putstr_w);
    ft_putstr("\n");
    btree_apply_suffix(root, &ft_putstr_w);
    ft_putstr("\n");
    btree_insert_data(&(root), strdup("d"), &ft_strcmp_w);
    btree_apply_infix(root, &ft_putstr_w);
    ft_putstr("\n");
    btree_insert_data(&(root), strdup("a"), &ft_strcmp_w);
    btree_apply_infix(root, &ft_putstr_w);
    ft_putstr("\n");
    btree_insert_data(&(root), strdup("b"), &ft_strcmp_w);
    btree_apply_infix(root, &ft_putstr_w);
    ft_putstr("\n\nex06 \n");
    // result = btree_search_item(root, strdup("b"), &ft_strcmp_w);
    // btree_apply_prefix(root, &ft_putstr_w);
    // ft_putstr("\n");
    result = btree_search_item(root, strdup("a"), &ft_strcmp_w);
    btree_apply_prefix(root, &ft_putstr_w);
    ft_putstr("\n");
    result = btree_search_item(root, strdup("c"), &ft_strcmp_w);
    btree_apply_prefix(root, &ft_putstr_w);
    ft_putstr("\n");
}
