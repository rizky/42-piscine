/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 13:11:15 by nschwarz          #+#    #+#             */
/*   Updated: 2017/08/21 21:48:22 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdlib.h>
# include <strings.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define NO_FILE	write(1, "file not found", 18)

typedef struct		s_bsq
{
	int				size;
	int				pos;
}					t_bsq;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putgrid(char **grid);

char				*ft_strcpy(char *dest, char *src);
char				*ft_strcat(char *dest, char *src);
char				*ft_strdup(char *src);

int					ft_strlen(char *str);
int					ft_strcmp(char *s1, char *s2);

void				ft_printmatrix(char **matrix);
char				**ft_create_matrix(int x, int y);
char				*ft_read_map(char *map);

t_bsq				*resolve(char *map, int x, int y);
void				ft_put_square(char *map, int pos, int size, int y);
void				ft_print(char *map);

#endif
