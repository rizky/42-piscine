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
	int	max;
	int	len_dest;
	int len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	max = len_dest + size - 1;

	i = 0;
	while (src[i] && (i < size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_dest + len_src);
}