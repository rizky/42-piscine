#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	*tmp;

	i = 2;
	if (ac == 1)
		return (0);
	list = ft_create_elem(av[1]);
	list->next = 0;
	while (i < ac)
	{
		tmp = list;
		list = ft_create_elem(av[i]);
		list->next = tmp;
		i++;
	}
	return (list);
}