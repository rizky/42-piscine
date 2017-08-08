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

int ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	len_dest;
	int len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);

	if (!dest[0]) {
        if (!src[0]) 
            return 0 ;
        return ft_strlen (src) ;
	}
	if (!src[0]) 
		return len_src + size;

	if (size < len_dest) 
        return len_src + size;

	i = 0;
	while (ft_strlen(dest) < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[ft_strlen(dest)] = '\0';
	return (len_dest + len_src);
}