/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:41:58 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 16:47:03 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	char	*ptr1;
	char	*ptr2;
	int		i;

	ptr1 = dest;
	while (*ptr1)
		ptr1++;
	ptr2 = src;
	i = 0;
	while (*ptr2 && i < nb)
	{
		*ptr1 = *ptr2;
		ptr2++;
		ptr1++;
		i++;
	}
	*ptr1 = '\0';
	return (dest);
}
