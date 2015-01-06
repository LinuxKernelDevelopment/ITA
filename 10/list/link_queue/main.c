#include <stdio.h>
#include "link_queue.h"

int main(void)
{
	struct link_queue lq;
	struct link_element *le;
	int i;
	init_queue(&lq);
	for (i = 0; i < 10; i++) {
		le = (struct link_element *)malloc(sizeof(struct link_element));
		le->value = i;
		enqueue(&lq, le);
	}
	for (i = 0; i < 10; i++)
		printf("%d\t", dequeue(&lq));
	printf("\n");
	return 0;
}
