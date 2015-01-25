#include <stdio.h>
#include <stdlib.h>

typedef struct element {
		int key;
} K;

K *direct_address_search(K *T[10], int k)
{
		return T[k];
}

void direct_address_insert(K *T[10], K x)
{
		*T[x.key] = x;
}

void direct_address_delete(K *T[10], K x)
{
		T[x.key] = NULL;
}

int
main(void)
{
		int i;
		K *T[10];
		for (i = 0; i < 10; i++)
				T[i] = malloc(sizeof(struct element));
		K k1 = {2};
		K k2 = {3};
		K k3 = {5};
		K k4 = {8};
		direct_address_insert(T, k1);
		direct_address_insert(T, k2);
		direct_address_insert(T, k3);
		direct_address_insert(T, k4);
		printf("%d\n", direct_address_search(T, 2)->key);
		printf("%d\n", direct_address_search(T, 3)->key);
		printf("%d\n", direct_address_search(T, 5)->key);
		printf("%d\n", direct_address_search(T, 8)->key);
		return 0;
}
