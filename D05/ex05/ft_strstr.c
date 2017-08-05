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
	char *ptr1;
	char *ptr2;
	char *ret;

	ptr1 = str;	
	while (*ptr1 != '\0')
	{
		ptr2 = to_find;
		ret = ptr1;
		while (*ptr2 != '\0')
		{
			if(*ret == *ptr2)
				ret++;
			else
				break ;
			ptr2++;
		}
		if(*ptr2 == '\0')
		{
			ret = ptr1;
			break ;
		}
		ret = 0;
		ptr1++;
	}

	return ret;
}
