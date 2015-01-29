#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

int
main(void)
{
	rbt root;
	int i;
	int key[] = { 1, 2, 4, 5, 7, 8, 11, 14, 15};
	rbn nil = { BLACK, 0, NULL, NULL, NULL};
	root.nil = &nil;
	root.root = &nil;
	rbn *tmp;
	for (i = 0; i < 9; i++) {
		tmp = malloc(sizeof(rbn));
		tmp->key = key[i];
		rb_insert(&root, tmp);
	}
	printf("\n");
	return 0;
}
