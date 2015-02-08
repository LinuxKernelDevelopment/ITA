#include <stdio.h>
#include "rbtree.h"
#include "stdlib.h"
#ifndef INTD
#include "int.h"
#endif

int main(void)
{
	rbt root;
	rbn nil = {BLACK, 0, {0, 0}, NULL, NULL, NULL, 0};
	root.nil = &nil;
	root.root = &nil;
	int i;
	INT a[11] = {{16, 21}, {0, 3}, {15, 23}, {19, 20}, {5, 8}, {26, 26}, {25, 30}, {8, 9}, {6, 10}, {17, 19}};
	rbn *tmp;
	for (i = 0; i < 11; i++) {
		tmp = malloc(sizeof(rbn));
		tmp->key = a[i].low;
		tmp->interval = a[i];
		tmp->max = a[i].high;
		rb_insert(&root, tmp);
	}
	inorder_rbtree_walk(&root, root.root);
	tmp = interval_search(&root, (INT){6, 7});
	printf("%d:%d\n", tmp->interval.low, tmp->interval.high);
	return 0;
}
