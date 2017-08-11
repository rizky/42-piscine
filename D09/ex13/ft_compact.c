int		ft_compact_count(char **tab, int length)
{
	int 	i;
	int		compact_len;

	i = 0;
	compact_len = 0;
	while(i < length)
	{
		if(tab[i][0] != '\0')
		{
			compact_len++;
		}
		i++;
	}
	return compact_len;
}

void	ft_copy_tab(char **dest, char **src, int length, int compact_len)
{
	int 	i;
	i = 0;
	while(i < compact_len)
	{
		dest[i] = src[i];
		i++;
	}
	while(i < length)
	{
		dest[i][0] = '\0';
		free(dest[i]);
		i++;
	}
}

int		ft_compact_b(char **tab, int length)
{
	int 	i;
	int		j;
	char	**compacttab;
	int		compact_len;
	
	compact_len = ft_compact_count(tab, length);
	compacttab = (char**)malloc(sizeof(*compacttab) * (compact_len + 1));
	i = 0;
	j = 0;
	while(i < length)
	{
		if(tab[i][0] != '\0')
		{
			compacttab[j] =  tab[i];
			j++;
		}
		i++;
	}
	ft_copy_tab(tab, compacttab, length, compact_len);
	return (compact_len);
}

int		ft_compact(char **tab, int length)
{
	int		a;
	int		nbr_mdf;

	a = -1;
	nbr_mdf = 0;
	while (++a < length)
	{
		if (tab[a][0] && nbr_mdf)
			tab[a - nbr_mdf] = tab[a];
		else
			++nbr_mdf;
	}
	return (length - nbr_mdf);
}
