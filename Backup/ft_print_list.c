#include <stdio.h>

void	ft_print_list_str(t_list *begin_list)
{
	t_list *list;

	list = begin_list;
	printf("[| ");
	while (list)
	{
		printf("%s", (char *)list->data);
		list = list->next;
		if (list)
			printf(" -> ");
	}
	printf(" |]\n");
}
