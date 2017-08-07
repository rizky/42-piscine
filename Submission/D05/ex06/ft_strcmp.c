/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 20:37:16 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/06 12:34:58 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	char	*ptr1;
	char	*ptr2;
	int		diff;

	diff = 0;
	ptr1 = s1;
	ptr2 = s2;
	while (*ptr1 != '\0' && *ptr2 != '\0')
	{
		diff = *ptr1 - *ptr2;
		if (diff > 0)
			break ;
		ptr1++;
		ptr2++;
	}
	return (*ptr1 - *ptr2);
}
