#include <stdio.h>
#include "link_stack.h"

int main(void)
{
	struct link_stack ls;
	struct link_element *le;
	int i;
	init_stack(&ls);
	for (i = 0; i < 10; i++) {
		le = (struct link_element *)malloc(sizeof(struct link_element));
		le->value = i;
		push(&ls, le);
	}
	for (i = 0; i < 10; i++)
		printf("%d\t", pop(&ls));
	printf("\n");
	return 0;
}
