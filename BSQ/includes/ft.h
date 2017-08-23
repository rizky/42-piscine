/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:47:09 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/21 17:47:09 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <stdlib.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_read_stdin(void);
void	ft_error(char *prog_name, char *arg);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
void	ft_putnbr(int nb);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
void	ft_putstr_at_once(char *str, int len);
char	*ft_strdup(char *src);
#endif
