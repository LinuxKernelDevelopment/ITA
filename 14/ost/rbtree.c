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
	y->size = x->size;
	x->size = x->left->size + x->right->size + 1;
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
	x->size = y->size;
	y->size = y->left->size + y->right->size + 1;
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
		x->size++;
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

void rb_transplant(rbt *T, rbn *u, rbn *v)
{
	if (u->p == T->nil)
		T->root = v;
	else if (u == u->p->left)
		u->p->left = v;
	else 
		u->p->right = v;
	v->p = u->p;
}

rbn* rb_minimum(rbt *T, rbn *x)
{
	while (x->left != T->nil)
		x = x->left;
	return x;
}

void rb_delete(rbt *T, rbn *z)
{
	rbn *x, *y = z;
	COLOR y_original_color = y->color;
	if (z->left == T->nil) {
		x = z->right;
		rb_transplant(T, z, z->right);
	} else if (z->right == T->nil) {
		x = z->left;
		rb_transplant(T, z, z->left);
	} else {
		y = rb_minimum(T, z->right);
		y_original_color = y->color;
		x = y->right;
		if (y->p == z)
			x->p = y;
		else {
			rb_transplant(T, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		rb_transplant(T, z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}
	if (y_original_color == BLACK)
		rb_delete_fixup(T, x);
}

void rb_delete_fixup(rbt *T, rbn *x)
{
	rbn *w, *y;
	while (x != T->root && x->color == BLACK)
	{
		if (x == x->p->left) {
			w = x->p->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				left_rotate(T, x->p);
				w = x->p->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			} else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(T, w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				left_rotate(T, x->p);
				x = T->root;
			}
		} else {
			w = x->p->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				right_rotate(T, x->p);
				w = x->p->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			} else {
				/*dbg(x, w);*/
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					left_rotate(T, w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				right_rotate(T, x->p);
				x = T->root;
			}
		}
	}
}

void dbg(rbn *x, rbn *w)
{
	if (x != NULL) printf("x:%d\n", x->key);
	if (w != NULL) printf("w:%d\n", w->key);
	if (x->p != NULL) printf("x->p:%d\n", x->p->key);
	if (w->p != NULL) printf("w->p:%d\n", w->p->key);
	if (x->left != NULL) printf("x->left:%d\n", x->left->key);
	if (x->right != NULL) printf("x->right:%d\n", x->right->key);
	if (w->left != NULL) printf("w->left:%d\n", w->left->key);
	if (w->right != NULL) printf("w->right:%d\n", w->right->key);
}

rbn* rb_search(rbn *x, int k)
{
	if (x == NULL || k == x->key)
		return x;
	if (k < x->key)
		return rb_search(x->left, k);
	else
		return rb_search(x->right, k);
}
