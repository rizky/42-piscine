#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# define BUF_SIZE 1024

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_error(char *prog_name, char *arg);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);
void	ft_print_memory(const void *addr, size_t size, int isC);
int		ft_strcmp(char *s1, char *s2);
#endif
