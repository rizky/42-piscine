#include "header.h"

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

int		main(int ac, char **av)
{
	t_str	str1, str2;
	int		k, i, j;
	t_list	*tmp;
	t_list	*tmp2;
	char str[2];

	k = 0;
	while (k < (ac == 1 ? K_MAX : ac - 1))
		switch (ac == 1 ? k++ : atoi(av[++k]))
		{
		case 0 :
			if (k + 1 < ac)
				str1 = av[++k];
			else
				str1 = strdup("a");
			printf("Ex 00 : expected [| %s |] :\t%s", str1, GREEN);
			ft_print_list_str(ft_create_elem(str1));
			printf("%s\n", END);
			break ;
		case 1 :
			if (k + 1 < ac)
				str1 = av[++k];
			else
				str1 = strdup("a");
			if (k + 1 < ac)
				str2 = av[++k];
			else
				str2 = strdup("b");
			tmp = ft_create_elem(str1);
			printf("Ex 01 :\n\t- expected [| %s -> %s -> %s |] (normal push back)\n\t\t%s", str1, str2, str2, GREEN);
			ft_list_push_back(&tmp, str2);
			ft_list_push_back(&tmp, str2);
			ft_print_list_str(tmp);
			printf("%s\t- expected [| %s -> %s |] (push back on an empty list)\n\t\t%s", END, str1, str2, GREEN);
			tmp = NULL;
			ft_list_push_back(&tmp, str1);
			ft_list_push_back(&tmp, str2);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;
		case 2 :			
			if (k + 1 < ac)
				str1 = av[++k];
			else
				str1 = strdup("a");
			if (k + 1 < ac)
				str2 = av[++k];
			else
				str2 = strdup("b");
			tmp = ft_create_elem(str1);
			printf("Ex 02 :\n\t- expected [| %s -> %s -> %s |] (normal front back)\n\t\t%s", str2, str2, str1, GREEN);
			ft_list_push_front(&tmp, str2);
			ft_list_push_front(&tmp, str2);
			ft_print_list_str(tmp);
			printf("%s\t- expected [| %s -> %s |] (push front on an empty list)\n\t\t%s", END, str2, str1, GREEN);
			tmp = NULL;
			ft_list_push_front(&tmp, str1);
			ft_list_push_front(&tmp, str2);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;
		case 3 :
			if (k + 1 < ac)
			{
				i = atoi(av[++k]);
				i *= (i < 0 ? -1 : 1);
			}
			else
				i = 13;
			j = -1;
			tmp = NULL;
			str1 = strdup("1");
			while (++j < i)
				ft_list_push_front(&tmp, str1);
			j = ft_list_size(tmp);
			ft_print_list_str(tmp);
			if (j == i)
				printf("%s[Ex03 OK]%s\t(tested on a list of %i elements)\n", GREEN, END, i);
			else
				printf("%s>>>[Ex03 FAIL]<<<%s\t(a list of %i elements is not %i element long)\n", RED, END, i, j);
			printf("%s\n", END);
			break ;
		case 4 :
			str1 = strdup("\e[1;31m>>>[Ex04 FAIL]<<<\e[0;0m");
			str2 = strdup("\e[1;32m[Ex04 OK]\e[0;0m");
			tmp = NULL;
			i = -1;
			ft_list_push_front(&tmp, str2);
			while (++i < 5)
				ft_list_push_front(&tmp, str1);
			ft_print_list_str(tmp);
			printf("%s\t(tested on a list of 50 elements)\n", (char*)ft_list_last(tmp)->data);
			break ;
		case 5 :
			printf("Ex05 : array to list :\n\t%s", GREEN);
			tmp = NULL;
			char	*words1[] = {"Hello", "How", "Are"};
			tmp = ft_list_push_params(3, words1);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;
		case 6 :
			printf("Ex06 : Should print empty list\n%s", GREEN);
			tmp = NULL;
			str1 = strdup("1");
			j = 0;
			while (++j < 5)
				ft_list_push_front(&tmp, str1);
			ft_print_list_str(tmp);
			printf("\n");
			ft_list_clear(&tmp);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;
		case 7 :
			printf("Ex07 : \n\t%s", GREEN);
			tmp = NULL;
			j = 0;
			while (++j < 5)
			{
				str[0] = j + '0';
				str[1] = '\0';
				ft_list_push_front(&tmp, strdup(str));
			}
			ft_print_list_str(tmp);
			ft_print_list_str(ft_list_at(tmp, 0));
			ft_print_list_str(ft_list_at(tmp, 1));			
			ft_print_list_str(ft_list_at(tmp, 2));
			ft_print_list_str(ft_list_at(tmp, 3));
			ft_print_list_str(ft_list_at(tmp, 4));
			ft_print_list_str(ft_list_at(tmp, 5));
			printf("%s\n", END);
			break ;
		case 8 :
			printf("Ex08 : Should reverse the linked list \n%s", GREEN);
			tmp = NULL;
			while (++j < 5)
			{
				str[0] = j + '0';
				str[1] = '\0';
				ft_list_push_front(&tmp, strdup(str));
			}
			ft_print_list_str(tmp);
			ft_list_reverse(&tmp);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;
		case 12 :
			printf("Ex12 : Should delete remove \n%s", GREEN);
			tmp = NULL;
			j = 0;
			while (++j <= 7)
			{
				str[0] = j + '0';
				str[1] = '\0';
				ft_list_push_front(&tmp, strdup(str));
			}
			ft_print_list_str(tmp);
			j = 8;
			while (--j >= 0)
			{
				str[0] = j + '0';
				str[1] = '\0';
				ft_list_remove_if(&tmp, str, &ft_strcmp);
				ft_print_list_str(tmp);
			}
			printf("%s\n", END);
			break ;		
		case 13 :
			printf("Ex13 : Should merge the lists \n%s", GREEN);
			tmp = NULL;
			tmp2 = NULL;
			j = 0;
			while (++j < 5)
			{
				str[0] = j + '0';
				str[1] = '\0';
				ft_list_push_front(&tmp, strdup(str));
			}
			j = 5;
			while (--j > 0)
			{
				str[0] = j + '0';
				str[1] = '\0';
				ft_list_push_front(&tmp2, strdup(str));
			}
			ft_print_list_str(tmp);
			ft_print_list_str(tmp2);
			ft_list_merge(&tmp, tmp2);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;	
		case 14 :
			printf("Ex14 : Should sort the list \n%s", GREEN);
			tmp = NULL;
			ft_list_push_front(&tmp, strdup("1"));
			ft_list_push_front(&tmp, strdup("5"));
			ft_list_push_front(&tmp, strdup("2"));
			ft_list_push_front(&tmp, strdup("2"));
			ft_list_push_front(&tmp, strdup("9"));
			ft_list_push_front(&tmp, strdup("6"));
			ft_print_list_str(tmp);
			ft_list_sort(&tmp, &ft_strcmp);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;	
		case 15 :
			printf("Ex15 : Should reverse the content of the list \n%s", GREEN);
			tmp = NULL;
			ft_list_push_front(&tmp, strdup("1"));
			ft_list_push_front(&tmp, strdup("5"));
			ft_list_push_front(&tmp, strdup("2"));
			ft_list_push_front(&tmp, strdup("2"));
			ft_list_push_front(&tmp, strdup("9"));
			ft_list_push_front(&tmp, strdup("6"));			
			ft_print_list_str(tmp);
			ft_list_reverse_fun(tmp);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;	
		case 16 :
			printf("Ex16 : Should be sorted list \n%s", GREEN);
			tmp = NULL;		
			ft_print_list_str(tmp);
			ft_sorted_list_insert(&tmp,strdup("jM"),&ft_strcmp);
			ft_print_list_str(tmp);
			ft_sorted_list_insert(&tmp,strdup("Hkh1Zw8"),&ft_strcmp);
			ft_print_list_str(tmp);
			ft_sorted_list_insert(&tmp,strdup("ndGY2Ls"),&ft_strcmp);
			ft_print_list_str(tmp);
			ft_sorted_list_insert(&tmp,strdup("dgUP8f"),&ft_strcmp);
			ft_print_list_str(tmp);
			ft_sorted_list_insert(&tmp,strdup("YGRXFD9"),&ft_strcmp);
			ft_print_list_str(tmp);
			ft_sorted_list_insert(&tmp,strdup("MGciqVg"),&ft_strcmp);
			ft_print_list_str(tmp);
			ft_sorted_list_insert(&tmp,strdup("QtjqcNO"),&ft_strcmp);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;		
		case 17 :
			printf("Ex16 : Should be sorted list \n%s", GREEN);
			tmp = NULL;
			tmp2 = NULL;
			ft_list_push_front(&tmp, strdup("6"));
			ft_list_push_front(&tmp, strdup("5"));
			ft_list_push_front(&tmp, strdup("4"));
			ft_list_push_front(&tmp, strdup("3"));
			ft_list_push_front(&tmp, strdup("2"));
			ft_list_push_front(&tmp, strdup("1"));			
			ft_print_list_str(tmp);
			ft_list_push_front(&tmp2, strdup("6"));
			ft_list_push_front(&tmp2, strdup("5"));
			ft_list_push_front(&tmp2, strdup("4"));
			ft_list_push_front(&tmp2, strdup("3"));
			ft_list_push_front(&tmp2, strdup("2"));
			ft_list_push_front(&tmp2, strdup("1"));			
			ft_print_list_str(tmp2);
			ft_sorted_list_merge(&tmp,tmp2,&ft_strcmp);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;									
		}
}
