#include <stdio.h>
#include "ost.h"

rbn *os_select(rbn *x, int i)
{
	int r;
	r = x->left->size + 1;
	if (i == r)
		return os_select(x->left, i);
	else
		return os_select(x->right, i - r);
}

int os_rank(rbt *T, rbn *x)
{
	int r;
	rbn *y;
	r = x->left->size + 1;
	y = x;
	while (y != T->root)
	{
		if (y == y->p->right)
			r = r + y->p->left->size + 1;
		y = y->p;
	}
	return r;
}
