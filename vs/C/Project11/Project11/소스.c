#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int rear;
	int front;
} QueueType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q) {
	q->front = q->rear = 0;
	 
}

int is_empty(QueueType *q) {
	return q->front == q->rear;
}


int is_full(QueueType *q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void queue_print(QueueType *q)
{
	printf("QUEUE(front=%d rear =%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d |", q->data[i]);

			if (i == q->rear)
			{
				printf("j\n");
				break;
			}
			printf("k,");
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType *q, element item) {
	if (is_full(q)) 
		error("큐가 포화상태입니다.");
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	
	
}

element dequeue(QueueType *q) {
	if (is_empty(q)) 
		error("큐가 공백상태입니다.");
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data [q->front];
}

element peek(QueueType *q) {
	if (is_empty(q)) 
		error("큐가 공백상태입니다.");
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
	
	
}

int main()
{
	QueueType q;
	int element;
	init_queue(&q);
	printf("front=%d rear=%d\n", q.front, q.rear);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("dequeue()=%d\n", dequeue(&q));
	enqueue(&q, 5);
	printf("dequeue()=%d\n", dequeue(&q));
	return 0;
}