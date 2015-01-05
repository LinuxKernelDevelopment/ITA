#define	LENGTH	10

typedef struct Queue {
	int head;
	int tail;
	int length;
	int Q[LENGTH];
} QUEUE;

void enqueue(struct Queue *, int);
int dequeue(struct Queue *);
