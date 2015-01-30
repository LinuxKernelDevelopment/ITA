#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

int
main(void)
{
	rbt root;
	root.root = NULL;
	int i;
	rbn nil = { BLACK, 0, NULL, NULL, NULL};
	root.nil = &nil;
	root.root = &nil;
	rbn *tmp;
	srand((unsigned int) 910216);
	for (i = 0; i < 0216 * 0216; i++) {
		tmp = malloc(sizeof(rbn));
		tmp->key = rand() % 910216;
		rb_insert(&root, tmp);
		printf("insert:%d\n", tmp->key);
	}
	return 0;
}
