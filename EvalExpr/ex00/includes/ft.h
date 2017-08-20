/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:30:14 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/14 20:30:15 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_swap(int *a, int *b);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcatch(char *dest, char src);
void	ft_putnbr(int nb);
char	*rush00(int x, int y, int len);
char	*rush01(int x, int y, int len);
char	**ft_split_once(char *str, char *charset);
char	*ft_strdup(char *src);
#endif
