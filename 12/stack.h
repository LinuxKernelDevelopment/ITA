#include "bst.h"
#define	LENGTH	10

typedef struct stack {
	int top;
	bn s[LENGTH];
} st;

int stack_empty(st*);
void push(st*, bn);
bn* pop(st*);

