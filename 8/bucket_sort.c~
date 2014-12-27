#include <stdio.h>
#include <stdlib.h>

typedef struct Belement {
	float B;
	struct Belement *next, *prev;
} Blist;

Blist* bucket_sort(int*, int);

#define LIST_HEAD_INIT(name) { 0.00, &(name), &(name) }

static inline void __list_add(Blist *new,
			      Blist *prev,
			      Blist *next)
{
	next->prev = new;
	new->next = prev;
	new->prev = prev;
	prev->next = new;
}

Blist *bucket_sort(int *A, int n)
{
	int i, p;
	Blist *Bl;
	Blist *tmp;
	Bl = malloc(sizeof(Blist) * 10);
	for (i = 0; i < 10; i++) {
		Bl[i].B = 0.00;
		Bl[i].next = &Bl[i];
		Bl[i].prev = &Bl[i];
	}
	for (i = 0; i < n; i++) {
		p = (int) n * A[i];
		tmp = malloc(sizeof(Blist));
		tmp->B = A[i];
		__list_add(tmp, &Bl[p], Bl[p].next);
	}
	return Bl;
}

int
main(int argc, char *argv[])
{
	Blist *blist;
	Blist bli, *tmpb;
	int i;
	int A[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
	blist = bucket_sort(A, sizeof(A) / sizeof(int));
	for (i = 0; i < 10; i++) {
		bli = blist[i];
		tmpb = bli.next;
		while (tmpb != &bli) {
			printf("%f\t", tmpb->B);
			tmpb = tmpb->next;
		}
		printf("\n");
	}

	return 0;
}
