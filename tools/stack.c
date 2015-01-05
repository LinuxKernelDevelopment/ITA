#include <stdio.h>
#include "stack.h"

int stack_empty(st *S)
{
	st stack = *S;
	if (stack.top == 0)
		return 1;
	else
		return 0;
}

void push(st *S, int x)
{
	if ((*S).top == LENGTH) {
		printf("overflow\n");
		return;
	}
	(*S).s[(*S).top++] = x;
}

int pop(st *S)
{
	if (stack_empty(S)) {
		printf("underflow\n");
		return -1;
	} else {
		(*S).top = (*S).top - 1;
		return (*S).s[(*S).top];
	}
}
