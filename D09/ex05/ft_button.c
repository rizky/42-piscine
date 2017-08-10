int		ft_button(int i, int j, int k)
{
	if((i < j) && (j < k))
		return j;
	if((j < i) && (i < k))
		return i;
	if((j < k) && (k < i))
		return k;
}