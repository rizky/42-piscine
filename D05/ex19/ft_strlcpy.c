/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 17:17:22 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 17:33:45 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*ptr;
	unsigned int		i;

	ptr = src;
	i = 0;
	while (*ptr)
	{
		ptr++;
		i++;
	}
	if(!size)
		return (i);
	dest = ft_strcpy(dest, src);
	return (i);
}
