#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"

typedef struct Belement {
	struct list_head list;
	float B;
} Blist;

Blist *bucket_sort(float*, int);
void list_insertion_sort(Blist*);

void list_insertion_sort(Blist *Bl)
{
	struct list_head *prev, *now, *after, *tmp, *first;
	prev = ((struct list_head *)Bl)->next;
	now = prev->next;
	after = now->next;
	first = prev;
	while (now != &Bl->list) {
		__list_del(prev, after);
		for (tmp = first; tmp != after; tmp = tmp->next) {
			if (list_entry(tmp, Blist, list)->B > list_entry(now, Blist, list)->B) 
				break;
		}
		tmp = tmp->prev;
		__list_add(now, tmp, tmp->next);
		prev = prev->next;
		now = prev->next;
		after = now->next;
	}
}


Blist *bucket_sort(float *A, int n)
{
	int i, p;
	Blist *tmp;
	Blist *Bl;
	Bl = malloc(sizeof(Blist) * 10);
	for (i = 0; i < 10; i++) {
		Bl[i].B = 0.00;
		INIT_LIST_HEAD(&(Bl[i].list));
	}
	for (i = 0; i < n; i++) {
		p = (int) n * A[i];
		tmp = malloc(sizeof(Blist));
		tmp->B = A[i];
		__list_add(&(tmp->list), &(Bl[p].list), Bl[p].list.next);
	}
	for (i = 0; i < n; i++) {
		list_insertion_sort(&Bl[i]);
	}
	return Bl;
}

int
main(void)
{
	Blist *blist;
	Blist bli;
	struct list_head *tmpb;
	int i, t = 0;
	float A[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
	float *result = malloc(sizeof(float) * (sizeof(A) / sizeof(float)));
	blist = bucket_sort(A, sizeof(A) / sizeof(float));
	for (i = 0; i < 10; i++) {
		tmpb = (&blist[i].list)->next;
		while (tmpb != &(blist[i].list)) {
			/*printf("%d\t", i);
			printf("%f\t", list_entry(tmpb, Blist, list)->B);*/
			result[t++] = list_entry(tmpb, Blist, list)->B;
			tmpb = tmpb->next;
		}
		/*printf("\n");*/	
	}
	for (i = 0; i < sizeof(A) / sizeof(float); i++)
		printf("%f\t", result[i]);
	printf("\n");
	return 0;
}


