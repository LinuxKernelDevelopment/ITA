#include <stdio.h>
#include "queue.h"

int main(void)
{
	struct Queue Q;
	Q.head = 0;
	Q.tail = 0;
	Q.length = LENGTH;
	int i;
	for (i = 0; i < 10; i++)
		enqueue(&Q, i);
	enqueue(&Q, 11);
	enqueue(&Q, 12);
	for (i = 0; i < 10; i++)
		printf("%d\t", dequeue(&Q));
	printf("\n");
	return 0;
}
