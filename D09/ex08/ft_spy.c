/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:19:12 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/11 14:19:13 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (!(s1[i] == ' ' || s2[i] == ' '))
			if ((s1[i] - s2[i]) != 0)
				return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

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

void	ft_skip_space(char *str, char *dest)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (str[j])
	{
		if (str[j] != ' ')
		{
			dest[k] = str[j];
			k++;
		}
		j++;
	}
	dest[k] = '\0';
}

int		main(int argc, char **argv)
{
	char	str[100];
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_skip_space(argv[i], str);
		ft_strlowcase(str);
		if (!(ft_strcmp(str, "president")) || !(ft_strcmp(str, "attack")))
		{
			ft_putstr("Alert!!!\n");
			return (0);
		}
		else if (!(ft_strcmp(str, "powers")))
		{
			ft_putstr("Alert!!!\n");
			return (0);
		}
		i++;
	}
	return (0);
}
