#include "bst.h"
#define	LENGTH	3000

typedef struct stack {
	int top;
	bn s[LENGTH];
} st;

int stack_empty(st*);
void push(st*, bn);
bn* pop(st*);

