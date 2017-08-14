int    ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int i;
    int min;
    int plus;

    min = 0;
    plus = 0;
    i = 0;
    while (i < length - 1)
    {
        if(f(tab[i], tab[i + 1]) > 0)
            min = min + 1;
        else
            plus = plus + 1;
        i++;
    }
    if (min == 0)
        return (1);
    else if (plus == 0)
        return (1);
    else
        return (0);
}