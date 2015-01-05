#include <stdio.h>
#include "stack.h"

int main(void)
{
	st s1;
	int i;
	s1.top = 0;
	for (i = 0; i < 10; i++)
		push(&s1, i);
	push(&s1, 10);
	return 0;
}
