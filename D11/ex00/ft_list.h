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
#endif