#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());
#endif