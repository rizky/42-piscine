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

#ifndef FT_OPP_H
# define FT_OPP_H
# include <unistd.h>

typedef struct		s_opp {
	char	*operator;
	void	*func;
}					t_opp;

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_mul(int a, int b);
int		ft_usage();
int 	ft_operate(int a, int b, int(*f)(int, int));
int		ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		ft_strcmp(char *s1, char *s2);

t_opp g_opptab[] =
{
	{"-", &ft_sub},
	{"+", &ft_add},
	{"*", &ft_mul},
	{"/", &ft_div},
	{"%", &ft_mod},
	{"", &ft_usage}
};
#endif
