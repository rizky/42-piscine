#include "ft_create_elem.c"
#include "ft_list.h"
#include "ft_print_list.c"
#include "ft_list_push_back.c"

int main()
{
	t_list *list;
	char str1[] = "Hello";
	char str2[] = "World";

	list = ft_create_elem(str1);
	ft_list_push_back(&list, str2);
	ft_print_list_str(list);
}