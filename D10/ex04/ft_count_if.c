 int    ft_count_if(char **tab, int(*f)(char*))
 {
    int i;
    int count;

    i = 0;
    count = 0;
    while (tab[i])
    {
        if(f(tab[i]))
        {
            count++;
            break ;
        }
        i++;
    }
    return (count);
 }