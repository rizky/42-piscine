#include "header.h"

void	ft_print_list_str(t_list *begin_list)
{
	t_list *cpy;

	cpy = begin_list;
	printf("[| ");
	while (cpy)
	{
		printf("%s", (char *)cpy->data);
		cpy = cpy->next;
		if (cpy)
			printf(" ; ");
	}
	printf(" |]\n");
}
