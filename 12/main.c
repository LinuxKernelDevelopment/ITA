#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int
main(void)
{
	bt root;
	root.root = NULL;
	int i;
	int key[] = {1, 4, 5, 10, 16, 17, 21};
	int num = sizeof(key) / sizeof(int);
	printf("num:%d\n", num);
	bn *tmp;
	for (i = 0; i < num; i++) {
		tmp = malloc(sizeof(bn));
		tmp->key = key[i];
		tmp->p = tmp->left = tmp->right = NULL;
		tree_insert_rec(&root, tmp);
	}
	tmp = tree_search(root.root, 10);
	inorder_tree_walk(root.root);
	printf("\n");
	tree_delete(&root, tmp);
	inorder_tree_walk(root.root);
	printf("\n");
	return 0;
}
