#include <stdio.h>
#include <stdio.h>
#include "queue.h"

int num(struct Queue *Q)
{
	if ((*Q).head <= (*Q).tail)
		return (*Q).tail - (*Q).head;
	else
		return (*Q).length - ((*Q).head - (*Q).tail);
}

void enqueue(struct Queue *Q, int x)
{
	int tail = (*Q).tail;
	if (num(Q) == (*Q).length) {
		printf("overflow\n");
		return;
	}
	(*Q).Q[tail] = x;
	if ((*Q).tail == (*Q).length)
		(*Q).tail = 1;
	else
		(*Q).tail = (*Q).tail + 1;
}

int dequeue(struct Queue *Q)
{
	int head = (*Q).head;
	if (num(Q) == 0) {
		printf("underflow\n");
		return -1;
	}
	int x = (*Q).Q[head];
	if ((*Q).head == (*Q).length)
		(*Q).head = 1;
	else
		(*Q).head = (*Q).head + 1;
	return x;
}
