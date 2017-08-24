#include "ft_btree.h"
#include <string.h>
#include <stdio.h>

void ft_putstr_w(void *data)
{
    ft_putstr((char*)data);
}

void	ft_putnbr(int nb)
{
	int tens;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb = nb * -1;
	}
	tens = 1;
	while (tens < nb / 10)
		tens = tens * 10;
	while (tens > 0)
	{
		ft_putchar(nb / tens + '0');
		nb = nb % tens;
		tens = tens / 10;
	}
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

void ft_putstr_w_level(void *data, int level, int is_root)
{
	ft_putstr((char*)data);
	ft_putnbr(level);
	ft_putnbr(is_root);
	ft_putstr("\n");
}

int main()
{
    t_btree *root;
	t_btree *result;
	t_btree *root2;

    root = btree_create_node(strdup("b"));
    root->left = btree_create_node(strdup("a"));
	root->right = btree_create_node(strdup("c"));
	ft_putstr("x01 \n");
    btree_apply_prefix(root, &ft_putstr_w);
	ft_putstr("\n\nex02 \n");
    btree_apply_infix(root, &ft_putstr_w);
	ft_putstr("\n\nex03 \n");
    btree_apply_suffix(root, &ft_putstr_w);
	ft_putstr("\n\nex04 \n");
    btree_insert_data(&(root), strdup("d"), &ft_strcmp_w);
    btree_apply_infix(root, &ft_putstr_w);
    ft_putstr("\n");
    btree_insert_data(&(root), strdup("a"), &ft_strcmp_w);
    btree_apply_infix(root, &ft_putstr_w);
    ft_putstr("\n");
    btree_insert_data(&(root), strdup("b"), &ft_strcmp_w);
    btree_apply_infix(root, &ft_putstr_w);
    ft_putstr("\n\nex05 \n");
    result = btree_search_item(root, strdup("b"), &ft_strcmp_w);
    btree_apply_prefix(root, &ft_putstr_w);
    ft_putstr("\n");
    result = btree_search_item(root, strdup("a"), &ft_strcmp_w);
    btree_apply_prefix(result, &ft_putstr_w);
    ft_putstr("\n");
    result = btree_search_item(root, strdup("c"), &ft_strcmp_w);
    btree_apply_prefix(result, &ft_putstr_w);
	ft_putstr("\n");
	ft_putstr("\n\nex06 \n");
	ft_putnbr(btree_level_count(root));
	ft_putstr("\n\nex07 \n");
	btree_insert_data(&(root2), strdup("By"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("USLejYI4Ns"), &ft_strcmp_w);	
	btree_insert_data(&(root2), strdup("Pz"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("LwHE"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("CUt3vck7PwV8"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("hkI"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("dG"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("MjL"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("H4zu6nblOM"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("1uWnN6"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("vDMfNS"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("W"), &ft_strcmp_w);
	btree_insert_data(&(root2), strdup("3ncWxdr"), &ft_strcmp_w);	
	btree_insert_data(&(root2), strdup("vNQx"), &ft_strcmp_w);
	btree_apply_by_level(root2, &ft_putstr_w_level);
}
