/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:51:30 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/05 20:27:05 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *ret;

	while (*str != '\0')
	{
		ret = str;
		while (*to_find != '\0')
		{
			if (*ret == *to_find)
				ret++;
			else
				break ;
			to_find++;
		}
		if (*to_find == '\0')
		{
			ret = str;
			break ;
		}
		ret = 0;
		str++;
	}
	return (ret);
}
