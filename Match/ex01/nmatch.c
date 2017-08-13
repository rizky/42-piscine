/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:16:10 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/13 18:16:11 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nmatch(char *s1, char *s2, int i, int j)
{
	int ret;

	ret = 0;
	if (s2[j] == '*')
	{
		if (s1[i])
			ret = ft_nmatch(s1, s2, i + 1, j) + ft_nmatch(s1, s2, i, j + 1);
		else
			ret = ft_nmatch(s1, s2, i, j + 1);
	}
	if (s2[j] == s1[i] && s1[i] && s2[j])
		ret = ft_nmatch(s1, s2, i + 1, j + 1);
	if (s1[i] == s2[j] && !s1[i] && !s2[j])
		ret = 1;
	return (ret);
}

int		nmatch(char *s1, char *s2)
{
	return (ft_nmatch(s1, s2, 0, 0));
}

