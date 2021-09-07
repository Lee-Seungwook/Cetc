#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
#define MAX_QUEUE_SIZE 100

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

int visited[MAX_VERTICES];

void graph_init(GraphType *g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void queue_init(QueueType *q)
{
	q->front = NULL;
	q->rear = NULL;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���:���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start];
}

void bfs_mat(GraphType* g, int v)
{
	int w;
	QueueType q;

	queue_init(&q);
	visited[v] = TRUE;
	printf("%d �湮 ->", v);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d�湮->", w);
				enqueue(&q, w);
			}
	}
}

int is_full(QueueType *q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}


void enqueue(QueueType *q, int item)
{
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->rear++;
	q->data[q->rear] = item;
}

int dequeue(QueueType *q)
{
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}
int main()
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	graph_init(g);
	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

	printf("�ʺ� �켱 Ž��\n");
	bfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0;
}
	