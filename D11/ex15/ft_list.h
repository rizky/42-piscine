#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

void	ft_list_reverse_fun(t_list *begin_list);
#endif