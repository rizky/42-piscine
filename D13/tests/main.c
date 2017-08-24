#include "ft_btree.h"
#include <string.h>
int main()
{
    t_btree *root;

    root = btree_create_node(strdup("Hello Word"));
}