/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:51:30 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 17:12:26 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strcat(char *dest, char *src)
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char	*ptr;
	int		i;

	ptr = src;
	i = 0;
	while (*ptr)
	{
		ptr++;
		i++;
	}
	dest = ft_strcat(dest, src);
	return (size + i);
}
