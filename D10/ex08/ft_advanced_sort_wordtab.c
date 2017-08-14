 void   ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
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
            if (cmp(tab[i], tab[j]) > 0)
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