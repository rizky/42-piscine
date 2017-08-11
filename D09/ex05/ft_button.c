int		ft_button(int i, int j, int k)
{
	if ((i <= j && j <= k) || (k <= j && j <= i))
		return (j);
	else if ((j <= k && k <= i) || (i <= k && k <= j))
		return (k);
	else
		return (i);
}