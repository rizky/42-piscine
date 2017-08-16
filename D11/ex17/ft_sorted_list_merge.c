#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	t_list	*list;
	t_list	*list2;
	t_list	*tmp;

	list = *begin_list1;
	if (list)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while ((*cmp)(list->data, data) <= 0 && list->next)
	{
		list = list->next;
	}
	while (list2)
	{
		tmp = list->next;
		list->next = list2;
		list = list->next;
		list->next = tmp;
	}
}
