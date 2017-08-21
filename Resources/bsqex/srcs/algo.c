#include "ft_header.h"

int snail(char *map, int pp, int step, int len)
{
	int i;
	int pos = pp + step;

//	printf("%d", pos);
	if (map[pos] != '.')
		return (0);
	i = 0;
	while (i < step  && map[pos] == '.')
	{
		pos += len;
		//	printf("%d", pos);
		if (map[pos] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < step && map[pos] == '.')
	{
		pos -= 1;
//		printf("%d", pos);
		if (map[pos] != '.')
			return (0);
		i++;
	}
	return (1 + snail(map, pp, step + 1, len));
}

t_bsq	*resolve(char *map, int X, int Y)
{
	int		i;
	t_bsq	*soluces;

	i = 0;
	soluces = (t_bsq*)malloc(sizeof(soluces) * (Y * X));
	while (i < X * Y)
	{
		soluces->size = snail(map, i, 0, Y);
		soluces->pos = i;
		i++;
		soluces++;
	}
	soluces->size = -1;
	return (soluces - (X * Y));
}
