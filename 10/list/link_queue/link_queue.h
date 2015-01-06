#include "list_head.h"

struct link_queue {
	struct list_head nil;
};

struct link_element {
	int value;
	struct list_head l;
};

void init_queue(struct link_queue *lq)
{
	INIT_LIST_HEAD(&(lq->nil));
}

void enqueue(struct link_queue *lq, struct link_element *le)
{
	__list_add(&(le->l), &(lq->nil), lq->nil.next);
}

int dequeue(struct link_queue *lq)
{
	int x = list_entry(lq->nil.prev, struct link_element, l)->value;
	__list_del(lq->nil.prev->prev, &(lq->nil));
	return x;
}


