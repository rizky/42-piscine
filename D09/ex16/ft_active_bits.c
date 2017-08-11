int	ft_active_bits(int value)
{
	int one;

	one = 0;
	while (value > 0)
	{
		if(value % 2 == 1)
			one++;
		value = value / 2;
	}
	return (one);
}
