#include "ft_list.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	char *c;

	c = str;
	while (*c != '\0')
	{
		ft_putchar(*c);
		c++;
	}
}

void print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->data);
		list = list->next;
	}
}

int main()
{
	t_list *list;
	char *str = "Hello";

	list = NULL;
	list = ft_create_elem(str);

	print_list(list);
}