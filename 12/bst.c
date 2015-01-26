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

void tree_insert(bt *T, bn *z)
{
	bn *y = NULL;
	bn *x = T->root;
	while (x != NULL) {
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->p = y;
	if (y == NULL)
		T->root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

void transplant(bt *T, bn *u, bn *v)
{
	if (u->p == NULL)
		T->root = v;
	else if (u == u->p->left)
		u->p->left = v;
	else 
		u->p->right = v;
	if (v != NULL)
		v->p = u->p;
}

void tree_delete(bt *T, bn *z)
{
	bn *y;
	if (z->left == NULL)
		transplant(T, z, z->right);
	else if (z->right == NULL)
		transplant(T, z, z->left);
	else {
		y = tree_minimum(z->right);
		if (y->p != z) {
			transplant(T, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		transplant(T, z, y);
		y->left = z->left;
		y->left->p = y;
	}
}

void tree_insert_rec_done(bn *p, bn *x, bn *z)
{
	if (x == NULL) {
		if (z->key < p->key) 
			p->left = z;
		else
			p->right = z;
		z->p = p;
		return;
	}
	if (z->key < x->key) 
		tree_insert_rec_done(x ,x->left, z);
	else
		tree_insert_rec_done(x, x->right, z);
}

void tree_insert_rec(bt *T, bn *z)
{
	bn *x = T->root;
	if (x == NULL) {
		T->root = z;
		return;
	}
	tree_insert_rec_done(T->root->p, x, z);
}

	
