#include "list_head.h"

struct link_stack {
	struct list_head nil;
};

struct link_element {
	int value;
	struct list_head l;
};

void init_stack(struct link_stack *ls)
{
	INIT_LIST_HEAD(&(ls->nil));
}

void push(struct link_stack *ls, struct link_element *le)
{
	__list_add(&(le->l), &(ls->nil), ls->nil.next);
}

int pop(struct link_stack *ls)
{
	int x = list_entry(ls->nil.next, struct link_element, l)->value;
	__list_del(&(ls->nil), ls->nil.next->next);
	return x;
}


