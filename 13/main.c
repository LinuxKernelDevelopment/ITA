#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

int
main(void)
{
	rbt root;
	int i;
	int key[] = { 1, 2, 4, 5, 7, 8, 11, 14, 15, 39, 29, 73, 24, 18, 18, 18, 18};
	int key2[] = {15, 14, 11, 8, 7, 5, 4, 2, 1, 18, 73, 24, 39, 29, 18, 18, 18};
	/*int key[] = {41, 38, 31, 12, 19, 8};
	int key2[] = { 8, 12, 19, 31, 38, 41};*/
	rbn nil = { BLACK, 0, NULL, NULL, NULL};
	root.nil = &nil;
	root.root = &nil;
	rbn *tmp;
	for (i = 0; i < sizeof(key2) / sizeof(int); i++) {
		tmp = malloc(sizeof(rbn));
		tmp->key = key2[i];
		rb_insert(&root, tmp);
		printf("insert:%d\n", tmp->key);
	}
	for (i = 0; i < sizeof(key) / sizeof(int); i++) {
		tmp = rb_search(root.root, key[i]);
		rb_delete(&root, tmp);
		printf("deleted:%d\n", tmp->key);
	}
	printf("\n");
	return 0;
}
