/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:36:26 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/14 20:36:47 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H
# include <stdlib.h>

typedef struct  s_stock_par {
int                 size_param;
char                *str;
char                *copy;
char                **tab;
}               t_stock_par;

char                **ft_split_whitespaces(char *str);
int                 ft_putchar(char c);
void                ft_show_tab(struct s_stock_par *par);
struct s_stock_par  *ft_param_to_tab(int ac, char **av);
#endif
