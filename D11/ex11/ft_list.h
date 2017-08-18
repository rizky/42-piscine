#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
#endif