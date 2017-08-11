int	ft_max(int *tab, int length)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (i < length)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}
