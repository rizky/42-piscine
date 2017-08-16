/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:11:26 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/15 15:11:27 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

int		ft_plus(int a, int b);
int		ft_minus(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_mul(int a, int b);
int		ft_operate(int a, int b, int (*f)(int, int));
int		ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		ft_strcmp(char *s1, char *s2);
#endif
