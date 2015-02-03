#include <stdio.h>
#include <stdlib.h>
#include "ost.h"
#ifndef RBTREE
#include "rbtree.h"
#endif

int
main(void)
{
	rbt root;
	int i;
	int arr[] = { 26, 17, 41, 14, 21, 30, 48, 10, 16, 19, 21, 28, 38, 7, 12, 14, 20, 35, 39, 3};
	rbn nil = {	BLACK, 0, 0, NULL, NULL, NULL};
	root.nil = &nil;
	root.root = &nil;
	rbn *tmp;
	for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
		tmp = malloc(sizeof(rbn));
		tmp->key = arr[i];
		tmp->size = 1;
		rb_insert(&root, tmp);
		printf("insert:%d\n", tmp->key);
	}
	printf("%d\n", os_rank(&root, root.root));
	printf("\n");
	return 0;
}
