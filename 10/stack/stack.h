#define	LENGTH	10

typedef struct stack {
	int top;
	int s[LENGTH];
} st;

int stack_empty(st*);
void push(st*, int);
int pop(st*);

