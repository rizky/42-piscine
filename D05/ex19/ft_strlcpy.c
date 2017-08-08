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

int ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;
	int len_src;
	int len;

	len_src = ft_strlen (src) ;
	len = len_src ;
	if (!dest[0] || size == 0) 
        return len_src ;
    
    if (size - 1 < len) {
        len = size - 1 ;
    }
    ft_strncpy (dest, src, len) ;
    dest [len] = '\0' ;
    return len_src ;
}
