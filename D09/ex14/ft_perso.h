/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu-au <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 04:21:22 by achiu-au          #+#    #+#             */
/*   Updated: 2017/08/11 04:38:13 by achiu-au         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

# define SAVE_THE_WORLD 1

struct					s_perso
{
	char				*name;
	float				life;
	unsigned int		age;
	int					profession;
};

typedef struct s_perso	t_perso;

#endif
