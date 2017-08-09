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
			return (str+i);
		i++;
	}
	return (NULL);
}

int		ft_strlen(char *str)
{
	char	*c;
	int		len;

	c = str;
	len = 0;
	while (*c)
	{
		len++;
		c++;
	}
	return (len);
}

int		ft_isvalid(char *base)
{
	int		i;
	char	*plus;
	char	*minus;
	char	*duplicate;
	char	s[2];

	plus = ft_strstr(base, "+");
	minus = ft_strstr(base, "-");
	i = 0;
	while (i < ft_strlen(base))
	{
		s[0] = base[i];
		duplicate = ft_strstr(base, s);
		if (duplicate == &base[i])
			duplicate = NULL;
		else
			break ;
		i++;
	}
	if (plus == NULL && minus == NULL && duplicate == NULL)
		i = 1;
	else
		i = 0;
	return (i);
}

int ft_atoi_base(char *str, char *base)
{
    int		ibase;
	int		sign;
	int		number;
    char    * alpha;
    int     offset;
    int     i;
    char	s[2];

	if (ft_isvalid(base))
	{
        ibase = ft_strlen(base);
        i = 0;
        sign = 1;
        number = 0;
        while (str[i] < ' ' || str[i] == '+')
            i++;
        if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        while (str[i] != '\0')
        {
            s[0] = str[i];
            s[1] ='\0';
            alpha = ft_strstr(base, s);
		    if (alpha)
            {
                offset = alpha - base;
                number = (number * ibase) + offset;
            }
            else
                break ;
            i++;
        }
        
    }
     return (number * sign);
}