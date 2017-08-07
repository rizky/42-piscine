/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 12:42:03 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 13:22:16 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char	*ptr1;
	char	*ptr2;
	int		diff;
	int		i;

	diff = 0;
	ptr1 = s1;
	ptr2 = s2;
	while ((*ptr1 != '\0' && i < n) && *ptr2 != '\0')
	{
		diff = *ptr1 - *ptr2;
		if (diff > 0)
			break ;
		ptr1++;
		ptr2++;
		i++;
	}
	return (*ptr1 - *ptr2);
}
