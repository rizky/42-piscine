#include <stdio.h>
#include "ft_strncpy.c"
#include <string.h>
int main(void)
{
	// char dest[10000] = "Hello World";
	// char src[] = "afada";
	
	// printf("%s\n", ft_strncpy(dest, src, 1000));

	// char dest1[10000] = "Hello World";
	// char src1[] = "afada";
	
	// printf("%s\n", strncpy(dest1, src1, 1000));
	// return (0);

	char src[] = "loulous";
   int i = 0;

   while (i < 30)
   {
    char dest[46] = "coucou les supers megas gigas";
    char dest1[36] = "coucou les supers megas gigas";
    printf("%s\n", ft_strncpy(dest, src, i));
    printf("%s\n", ft_strncpy(dest1, src, i));
       i += 5;
   }

   printf("\n \n");

   i = 0;
   while (i < 30)
   {
    char dest[46] = "coucou les supers megas gigas";
    char dest1[36] = "coucou les supers megas gigas";
    printf("%s\n", strncpy(dest, src, i));
    printf("%s\n", strncpy(dest1, src, i));
       i += 5;
   }


//  printf("%s\n", strcpy("coucou les", "loulous"));

   return (0);
}

