#ifndef FT_BTREE_RB_H
# define FT_BTREE_RB_H

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;
enum    e_rb_color
{
	RB_BLACK,
	RB_RED
};
typedef struct s_rb_node
{
	struct s_rb_node *parent;
	struct s_rb_node *left;
	struct s_rb_node *right;
	void			*data;
	enum			e_rb_color  color;
} t_rb_node;

#endif
