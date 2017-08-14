int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void ft_sort_wordtab(char **tab)
{
    int     i;
    int     j;
    char    *temp;

    i = 0;
    while (tab[i])
    {
        j = i;
        while (tab[j])
        {
            if (ft_strcmp(tab[i], tab[j]) > 0)
			{
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}