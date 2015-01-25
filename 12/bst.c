#include <stdio.h>
#include "stack.h"
#ifndef BST
#include "bst.h"
#endif

void inorder_tree_walk(bn *x)
{
	if (x != NULL) {
		inorder_tree_walk(x->left);
		printf("%d\t", x->key);
		inorder_tree_walk(x->right);
	}
}

void inorder_tree_walk_nore(bn *x)
{
	st stack;
    push(&stack, *x);
	while (x || !stack_empty(&stack)) {
		while (x->left != NULL) {
			push(&stack, *x->left);
			x = x->left;
		}
		while (!stack_empty(&stack)) {
			x = pop(&stack);
			printf("%d\t", x->key);
			x = x->right;
			if (x) {
				push(&stack, *x);
				break;
			}
		}
	}
}

bn* tree_search(bn *x, int k)
{
	if (x == NULL || k == x->key)
		return x;
	if (k < x->key)
		return tree_search(x->left, k);
	else
		return tree_search(x->right, k);
}

bn* iterative_tree_search(bn *x, int k)
{
	while (x != NULL && k != x->key) {
		if (k < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

bn* tree_minimum(bn *x)
{
	while (x->left != NULL)
		x = x->left;
	return x;
}

bn* tree_maximum(bn *x)
{
	while (x->right != NULL)
		x = x->right;
	return x;
}

bn* tree_successor(bn *x)
{
	bn *y;
	if (x->right != NULL)
		return tree_minimum(x->right);
	y = x->p;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->p;
	}
	return y;
}

bn* tree_minimum_rec(bn *x)
{
	if (x->left == NULL)
		return x;
	tree_minimum_rec(x->left);
}

bn* tree_maximum_rec(bn *x)
{
	if (x->right == NULL)
		return x;
	tree_maximum_rec(x->right);
}

bn* tree_predecessor(bn *x)
{
	bn *y;
	if (x->left != NULL)
		return tree_maximum(x->left);
	y = x->p;
	return y;
}
