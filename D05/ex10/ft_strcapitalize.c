/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 14:01:53 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 14:24:37 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	str = ft_strlowcase(str);
	if (str[0] != '\0')
		str[0] = str[0] - 'a' + 'A';
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
			if (str[i + 1] != '\0')
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
					str[i + 1] = str[i + 1] - 'a' + 'A';
		i++;
	}
	return (str);
}
