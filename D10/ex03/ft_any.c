int     ft_any(char **tab, int(*f)(char*))
{
    int i;
    int valid;

    i = 0;
    valid = 0;
    while (tab[i])
    {
        if(f(tab[i]))
        {
            valid = 1;
            break ;
        }
        i++;
    }
    return (valid);
}