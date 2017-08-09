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

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char				*ptr1;
	char				*ptr2;
	int					i;
	unsigned int		len_dest;
	unsigned int		len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	ptr1 = dest;
	while (*ptr1)
		ptr1++;
	ptr2 = src;
	i = 0;
	while (*ptr2 && i + len_dest < size - 1)
	{
		*ptr1 = *ptr2;
		ptr2++;
		ptr1++;
		i++;
	}
	*ptr1 = '\0';
	if (len_dest > size)
		len_dest = size;
	return (len_dest + len_src);
}
