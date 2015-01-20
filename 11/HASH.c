#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"

typedef struct element {
		int key;
		struct list_head llist;
} K;

#define h(key)	key % 8

void chained_hash_insert(struct list_head T[8], K *x)
{
	__list_add(&x->llist, &T[h(x->key)], T[h(x->key)].next);
}

K *chained_hash_search(struct list_head T[8], int k)
{
	struct list_head head, *p;
	K *result;
	head = T[h(k)];
	p = head.next;
	while (p != head.prev->next) {
		if (p == head.prev->next) break;
		result = list_entry(p, K, llist);
		if (result->key == k) 
			return result;
		p = p->next;
	}
	return NULL;
}

void chained_hash_delete(struct list_head T[8], K *x)
{
	__list_del(x->llist.prev, x->llist.next);
}

int
main(void)
{
		int i;
		struct list_head T[10];
		K *element;
		for (i = 0; i < 10; i++)
			INIT_LIST_HEAD(&T[i]);

		int num[] = {5, 28, 19, 15, 20, 33, 12, 17, 10};
		for (i = 0; i < sizeof(num) / sizeof(int); i++)
		{
			element = malloc(sizeof(K));
			element->key = num[i];
			chained_hash_insert(T, element);
		}
		printf("%d\n", chained_hash_search(T, 33)->key);
		return 0;
}
