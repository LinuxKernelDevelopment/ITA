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
	y->right = x->left;
	if (x->left != T->nil)
		x->left->p = y;
	x->p = y->p;
	if (y->p == T->nil)
		T->root = x;
	else if (y == y->p->left)
		y->p->left = x;
	else
		y->p->right = x;
	x->left = y;
	y->p = x;
}
	
