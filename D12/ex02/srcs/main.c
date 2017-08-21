#include "ft.h"

void	ft_read_file(int fd, int line)
{
	char 	*input;
	char	*buf;
	int		ret;
	int		i;
	int		j;

	input = (char*)malloc(sizeof(char));;
	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		input = ft_strcat(input, buf);
	}

	i = ft_strlen(input) - line;
	if (i < 0 )
		i = 0;
	j = 0;
	while (input[j])
	{
		if (j >= i)
			ft_putchar(input[j]);
		j++;
	}
}

void	ft_display_file(char *prog_name, char *charlimit, char *arg)
{
	int		fd;

	errno = 0;
	fd = open (arg, O_RDWR);
	if (fd == -1)
			ft_error(prog_name, arg);
	else
		ft_read_file(fd, ft_atoi(charlimit));
	if (close(fd) == -1 && fd == 3)
		ft_putstr("Failed to close");
}

int		main(int argc, char **argv)
{
	int i;

	i = 3;
	while (i < argc)
	{
		if (argc > 4)
		{
			if (i > 3)
				ft_putstr("\n");
			ft_putstr("==> ");
			ft_putstr(argv[i]);
			ft_putstr(" <==\n");
		}
		ft_display_file (argv[0], argv[2], argv[i]);
		i++;
	}
	return (0);
}
