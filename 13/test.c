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
		if (!rb_search(root.root, tmp->key))
			rb_insert(&root, tmp);
	}
	for (i = 0; i < 0216 * 0216; i++) {
		tmp = rb_search(root.root, rand() % 910216);
		if (tmp != NULL)
			rb_delete(&root, tmp);
		if (tmp != NULL)
			if (rb_search(root.root, tmp->key)) {
				printf("error exit");
				exit(0);
			}
	}
	return 0;
}
