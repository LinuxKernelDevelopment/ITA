#include <stdio.h>
#include <stdlib.h>

#define	NIL	{-1}
#define	DELETED	{-2}
#define OVERROR	{-3}
#define	h(k, i)	(9 * k + i) % 10

typedef struct element {
		int key;
} K;

int hash_insert(K T[10], K x)
{
	int i, j;
	i = 0;
	do {
		j = h(x.key, i);
		if (T[j].key == ((K)NIL).key || T[j].key == ((K)DELETED).key)
		{
			T[j] = x;
			return j;
		}
		else
			i++;
	} while (i != 10);
	printf("hash table overflow\n");
	return -1;
}

int hash_search(K T[10], K x)
{
	int i, j;
	i = 0;
	do {
		j = h(x.key, i);
		if (T[j].key == x.key)
			return j;
		i++;
	} while (T[j].key != ((K)NIL).key && i != 10);
	return -1;
}

int hash_delete(K T[10], K x)
{
	int i, j;
	i = 0;
	do {
		j = h(x.key, i);
		if (T[j].key == x.key)
		{
			T[j] = (K) DELETED;
			return j;
		}
		i++;
	} while (T[j].key != ((K)NIL).key && i != 10);
	return -1;
}

int
main(void)
{
		int i;
		K T[10];
		for (i = 0; i < 10; i++)
			T[i] = (K) NIL;
		K k1 = {2};
		K k2 = {3};
		K k3 = {5};
		K k4 = {8};
		hash_insert(T, k1);
		hash_insert(T, k2);
		hash_insert(T, k3);
		hash_insert(T, k4);
		hash_delete(T, k1);
		printf("%d\n", hash_search(T, k1));
		printf("%d\n", hash_search(T, k2));
		printf("%d\n", hash_search(T, k3));
		printf("%d\n", hash_search(T, k4));
		return 0;
}
