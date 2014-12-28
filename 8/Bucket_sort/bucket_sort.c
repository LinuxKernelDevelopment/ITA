#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"

typedef struct Belement {
	struct list_head list;
	float B;
} Blist;

struct list_head *bucket_sort(float*, int);


struct list_head *bucket_sort(float *A, int n)
{
	int i, p;
	Blist *tmp;
	struct list_head *Bl;
	Bl = malloc(sizeof(struct list_head) * 10);
	for (i = 0; i < 10; i++) {
		INIT_LIST_HEAD(Bl);
	}
	for (i = 0; i < n; i++) {
		p = (int) n * A[i];
		tmp = malloc(sizeof(Blist));
		tmp->B = A[i];
		__list_add(&(tmp->list), Bl, Bl->next);
	}
	return Bl;
}

int
main(void)
{
	struct list_head *blist;
	Blist bli;
	struct list_head *tmpb;
	int i;
	float A[] = {0.78, 0.77};
	blist = bucket_sort(A, sizeof(A) / sizeof(int));
	for (i = 0; i < 10; i++) {
		tmpb = blist[i].next;
		while (tmpb->next != blist[i]) {
			printf("%f\t", list_entry(tmpb, Blist, list)->B);
			tmpb = tmpb->next;
		}
		printf("\n");	
	}

	return 0;
}


