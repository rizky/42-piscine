#ifndef FT_STOCK_PAR_H
#define FT_STOCK_PAR_H
#include <stdlib.h>
char	**ft_split_whitespaces(char *str);
char	*ft_strdup(char *src);
typedef struct s_stock_par {
int size_param; char *str;
char *copy;
char **tab;
}			t_stock_par;
#endif