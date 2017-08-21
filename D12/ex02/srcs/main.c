#include "ft.h"

int		ft_get_row(char *str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			len++;
		i++;
	}
	if (str[0] != '\0')
		len = len + 1;
	return (len);
}

void	ft_read_file(int fd, int line)
{
	char 	*input;
	char	*buf;
	int		ret;
	int		i;
	int		j;
	int		nl_counter;

	input = (char*)malloc(sizeof(char));;
	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		input = ft_strcat(input, buf);
	}

	i = ft_get_row(input) - line;
	if (i < 0 )
		i = 0;
	j = 0;
	nl_counter = 0;
	while (input[j])
	{
		if (input[j] == '\n' && nl_counter < i -1)
		{
			nl_counter++;
			j++;
		}
		if (nl_counter >= i - 1)
			ft_putchar(input[j]);
		j++;
	}
}

void	ft_display_file(char *prog_name, char *arg)
{
	int		fd;

	errno = 0;
	fd = open (arg, O_RDWR);
	if (fd == -1)
			ft_error(prog_name, arg);
	else
		ft_read_file(fd, 10);
	if (close(fd) == -1 && fd == 3)
		ft_putstr("Failed to close");
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argc > 2)
		{
			if (i > 1)
				ft_putstr("\n");
			ft_putstr("==> ");
			ft_putstr(argv[i]);
			ft_putstr(" <==\n");
		}
		ft_display_file (argv[0], argv[i]);
		i++;
	}
	return (0);
}
