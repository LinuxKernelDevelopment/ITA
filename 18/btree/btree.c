#include "btree.h"
#include <stdlib.h>

void disk_read(btree *c) {}
void disk_write(btree *c) {}
BTRR	*b_tree_search(btree *x, char k)
{
	int i;

	i = 1;
	while (i <= x->n && k > x->key[i])
		i += 1;
	if (i <= x->n && k == x->key[i])
		return &((BTRR){x, i});
	else if(x->leaf)
		return NULL;
	else
	{
		disk_read(x->c[i]);
		return b_tree_search(x->c[i], k);
	}
}

void b_tree_create(struct BTREE *T)
{
	btree *x;

	x = malloc(sizeof(btree));
	x->leaf = TRUE;
	x->n = 0;
	disk_write(x);
	T->root = x;
}

void b_tree_split_child(btree *x, int i)
{
	btree *z, *y;
	int j;

	z = malloc(sizeof(btree));
	y = x->c[i];
	z->leaf = y->leaf;
	z->n = t - 1;
	for (j = 1; j <= t - 1; j++)
		z->key[j] = y->key[j + t];
	if (!y->leaf)
		for (j = 1; j <= t; j++)
			z->c[j] = y->c[j + t];
	y->n = t - 1;
	for (j = x->n + 1; j >= i + 1; j--)
		x->c[j + 1] = x->c[j];
	x->c[i + 1] = z;
	for (j = x->n; j >= i; j--)
		x->key[j + 1] = x->key[j];
	x->key[i] = y->key[t];
	x->n += 1;
	disk_write(y);
	disk_write(z);
	disk_write(x);
}

void b_tree_insert_nofull(btree*, int);
void b_tree_insert(struct BTREE *T, int k)
{
	btree *r, *n, *s;

	r = T->root;
	if (r->n == 2 * t - 1)
	{
		s = malloc(sizeof(btree));
		T->root = s;
		s->leaf = FALSE;
		s->n = 0;
		s->c[1] = r;
		b_tree_split_child(s, 1);
		b_tree_insert_nofull(s, k);
	} else
		b_tree_insert_nofull(r, k);
}

void b_tree_insert_nofull(btree *x, int k)
{
	int i;

	i = x->n;
	if (x->leaf) {
		while (i >= 1 && k < x->key[i])
		{
			x->key[i + 1] = x->key[i];
			i = i - 1;
		}
		x->key[i + 1] = k;
		x->n = x->n + 1;
		disk_write(x);
	} else {
		while (i >= 1 && k < x->key[i])
			i = i - 1;
		i = i + 1;
		disk_read(x->c[i]);
		if (x->c[i]->n == 2 * t - 1) {
			b_tree_split_child(x, i);
			if (k > x->key[i])
				i = i + 1;
		}
		b_tree_insert_nofull(x->c[i], k);
	}
}
