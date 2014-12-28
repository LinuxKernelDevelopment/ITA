#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"

typedef struct Belement {
	struct list_head list;
	float B;
} Blist;

Blist *bucket_sort(float*, int);


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
	return Bl;
}

int
main(void)
{
	Blist *blist;
	Blist bli;
	struct list_head *tmpb;
	int i;
	float A[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
	blist = bucket_sort(A, sizeof(A) / sizeof(int));
	for (i = 0; i < 10; i++) {
		tmpb = (&blist[i].list)->next;
		while (tmpb != &(blist[i].list)) {
			printf("%d\t", i);
			printf("%f\t", list_entry(tmpb, Blist, list)->B);
			tmpb = tmpb->next;
		}
		printf("\n");	
	}

	return 0;
}


