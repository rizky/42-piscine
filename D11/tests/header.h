#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

# define GREEN "\e[1;32m"
# define END "\e[0;0m"
# define RED "\e[1;31m"
# define K_MAX 6

typedef char		*t_str;
typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void				ft_print_list_str(t_list *begin_list);
t_list				*ft_create_elem(void *data);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
t_list				*ft_list_last(t_list *begin_list);
t_list				*ft_list_push_params(int ac, char **av);

#endif
