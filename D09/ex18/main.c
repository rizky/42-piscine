#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_join.c"

int main(){
    // allocate space for 5 pointers to strings
    char **strings = (char**)malloc(5*sizeof(char*));
    int i = 0;
    //allocate space for each string
    // here allocate 50 bytes, which is more than enough for the strings
    for(i = 0; i < 5; i++){
        printf("%d\n", i);
        strings[i] = (char*)malloc(50*sizeof(char));
    }
    //assign them all something
    sprintf(strings[0], "a");
    sprintf(strings[1], "b");
    sprintf(strings[2], "c");
    sprintf(strings[3], "d");
    strings[4] = NULL;
    // Print it out
	i = 0;
    while (strings[i] != NULL)
	{
        printf("#%d(length: %lu): %s\n", i, strlen(strings[i]),strings[i]);
		i++;
    } 

	// char sep = '%';
	printf("%s\n", ft_join(strings, "1212"));
    return 0;
}