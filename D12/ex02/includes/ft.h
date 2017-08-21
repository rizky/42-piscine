#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <stdlib.h>
# define BUF_SIZE 1024

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_display_file(char *prog_name, char *arg);
void	ft_error(char *prog_name, char *arg);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
#endif
