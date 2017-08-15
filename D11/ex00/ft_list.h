#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>
# include <unistd.h>
typedef struct s_list t_list;

struct	s_list 
{
	void	*data;
	t_list	*next;
};

t_list *ft_create_elem(void *data);
void	ft_list_push_back(t_list **begin_list, void *data);
#endif