#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define END "\033[1;0m"

// gcc -o main main.c ../ex01/ft_foreach.c ../ex02/ft_map.c ../ex03/ft_any.c ../ex04/ft_count_if.c ../ex05/ft_is_sort.c ../tests/ft_putchar.c ../tests/ft_putstr.c

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_foreach(int *tab, int length, void (*f)(int));
int		*ft_map(int *map, int length, int (*f)(int));
int		ft_any(char **tab, int (*f)(char *));
int		ft_count_if(char **tab, int (*f)(char *));
int		ft_is_sort(int *tab, int length, int (*f)(int, int));
void	ft_sort_wordtab(char **tab);
void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *));

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(48 + n % 10);
}

int		ft_abs_half(int i)
{
	i = (i < 0 ? -i : i);
	return (i >> 1);
}

int		isupcase(char *str)
{
	if (!*str)
		return (1);
	return ('A' <= *str && *str <= 'Z' ? isupcase(str + 1) : 0);
}

void	ft_print(char *str, char *color)
{
	printf("%s%s%s\n", color, str, END);
}

int		cmp(int a, int b)
{
	return (b - a);
}

int		cmpstr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return  (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		k;
	int		pi[] = {14, 15, 92, 65, 35, 89, 79, 32, 38, 46, 26, 43, 38, 32, 79, 50};
	int		tab[] = {10, 20, 30, 40};
	char	*words1[] = {"Hello", "World", "RTFM", "LMGIFY", "GIYF", "NSFW", 0};
	char	*words3[] = {"Hello", "World", "RTFM", "LMGIFY", "GIYF", "NSFW", 0};
	char	*words2[] = {"O miseras", "homini", "mentis", "O pectora", "caeca", 0};

	k = -1;
	while (++k < (ac == 1 ? 8 : ac))
		switch (ac == 1 ? k : atoi(av[k]))
		{
		case 1 :
			ft_putstr("Ex01 : Pi = 3,");
			ft_putstr(GREEN);
			ft_foreach(pi, 16, &ft_putnbr);
			ft_putstr(END);
			ft_putstr("...\n");
			break ;
		case 2 :
			ft_putstr("Ex02 : Expected \"5101520\" : \"");
			ft_foreach(ft_map(tab, 4, &ft_abs_half), 4, &ft_putnbr);
			ft_putstr("\"\n");
			break ;
		case 3 :
			if (ft_any(words1, &isupcase) && !ft_any(words2, &isupcase))
				ft_print("[Ex03 OK]", GREEN);
			else
				ft_print(">>>[Ex03 FAIL]<<<", RED);
			break ;
		case 4 :
			if (ft_count_if(words1, &isupcase) == 4 && !ft_count_if(words2, &isupcase))
				ft_print("[Ex04 OK]", GREEN);
			else
				ft_print(">>>[Ex04 FAIL]<<<", RED);
			break ;
		case 5 :
			if (ft_is_sort(tab, 4, &cmp) && !ft_is_sort(pi, 16, &cmp))
				ft_print("[Ex05 OK]", GREEN);
			else
				ft_print(">>>[Ex06 FAIL]<<<", RED);
			break ;
		case 6 :
			ft_putstr("\nEx07\n\n");
			ft_sort_wordtab(words1);
			int i = 0;
			while (words1[i])
			{
				ft_putstr(words1[i]);
				ft_putchar('\n');
				i++;
			}
			break ;
		case 7 :
			ft_putstr("\nEx08\n\n");
			ft_advanced_sort_wordtab(words3, &cmpstr);
			int j = 0;
			while (words3[j])
			{
				ft_putstr(words3[j]);
				ft_putchar('\n');
				j++;
			}
			break ;
		case 8 :
			
			break ;
		}
	return (0);
}
