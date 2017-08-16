#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*list;

	list = *begin_list;
	while (list)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = 0;
		free(list);
		list = tmp;
	}
}