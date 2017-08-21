/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:51:24 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/21 17:51:24 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	ft_print_memory(const void *addr, size_t size, int is_c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar_mem(unsigned char const *ptr);
#endif
