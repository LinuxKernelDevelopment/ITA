#include <stdio.h>
#include "rbtree.h"

void left_rotate(rbt *T, rbn *x)
{
	rbn *y = x->right;
	x->right = y->left;
	if (y->left != T->nil)
		y->left->p = x;
	y->p = x->p;
	if (x->p == T->nil)
		T->root = y;
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;
	y->left = x;
	x->p = y;
}

void right_rotate(rbt *T, rbn *y)
{
	rbn *x = y->left;
	y->left = x->right;
	if (x->right != T->nil)
		x->right->p = y;
	x->p = y->p;
	if (y->p == T->nil)
		T->root = x;
	else if (y == y->p->left)
		y->p->left = x;
	else
		y->p->right = x;
	x->right = y;
	y->p = x;
}

void rb_insert(rbt *T, rbn *z)
{
	rbn *y = T->nil;
	rbn *x = T->root;
	while (x != T->nil)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->p = y;
	if (y == T->nil)
		T->root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = T->nil;
	z->right = T->nil;
	z->color = RED;
	rb_insert_fixup(T, z);
}

void rb_insert_fixup(rbt *T, rbn* z)
{
	rbn* y;
	while (z->p->color == RED)
	{
		if (z->p == z->p->p->left)
		{
			y = z->p->p->right;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else 
			{
				if (z == z->p->right) {
					z = z->p;
					left_rotate(T, z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				right_rotate(T, z->p->p);
			}
		} else {
			y = z->p->p->left;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			} else {
				if (z == z->p->left) {
					z = z->p;
					right_rotate(T, z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				left_rotate(T, z->p->p);
			}
		}
	}
	T->root->color = BLACK;
}
