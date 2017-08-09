/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:37:55 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/08 15:10:53 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_arg(int argc, char **argv, int *order)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[order[i]][j])
		{
			ft_putchar(argv[order[i]][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

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

int		main(int argc, char **argv)
{
	int	order[argc];
	int i;
	int j;
	int temp;

	i = 0;
	while (++i < argc)
		order[i] = i;
	i = 0;
	while (++i < argc)
	{
		j = i;
		while (j < argc)
		{
			if (ft_strcmp(argv[order[i]], argv[order[j]]) > 0)
			{
				temp = order[i];
				order[i] = order[j];
				order[j] = temp;
			}
			j++;
		}
	}
	ft_print_arg(argc, argv, order);
	return (0);
}
