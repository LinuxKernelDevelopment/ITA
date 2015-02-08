#include "int.h"
#include "rbtree.h"

rbn *interval_search(rbt *T, INT i)
{
	rbn *x;
	x = T->root;
	while (x != T->nil && (x->interval.high < i.low || i.high < x->interval.low))
	{
		if (x->left != T->nil && x->left->max >= i.low)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}
