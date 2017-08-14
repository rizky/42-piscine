#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j])
		{
			if (str[i + j] == to_find[j])
				j++;
			else
				break ;
		}
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (NULL);
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_atoi_base(char *str, char *base)
{
	int		number;
	int		i;
	char	s[2];
	int		len;
	
	i = 0;
	number = 0;
	while (str[i] != '\0')
	{
		s[0] = str[i];
		s[1] = '\0';
		if (ft_strstr(base, s))
			number = (number * ft_strlen(base)) + ft_strstr(base, s) - base;
		else
			break ;
		i++;
	}
	return (number);
}

void		ft_itoa_base(int number, char *base, int *count, char **res)
{
	if(number /  ft_strlen(base) > 0)
	{
		*count = *count +1;
		ft_itoa_base(number / ft_strlen(base), base, count, res);
	}
	else
	{
		*count = *count +1;
		*res = (char*)malloc(sizeof(char) * (*count + 2));
	}
	*count = *count - 1;
	(*res)[*count] = base [number % ft_strlen(base)];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	dec;
	char *res;
	int count;

	dec = ft_atoi_base(nbr, base_from);
	count = 0;
	ft_itoa_base(dec, base_to, &count, &res);
	return (res);
}