/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 15:32:23 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 16:39:56 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = dest;
	while (*ptr1)
		ptr1++;
	ptr2 = src;
	while (*ptr2)
	{
		*ptr1 = *ptr2;
		ptr2++;
		ptr1++;
	}
	*ptr1 = '\0';
	return (dest);
}
