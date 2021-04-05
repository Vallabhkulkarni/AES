typedef struct queue {
	int rear, front, size;
	int *Q;
}queue;

void init_queue(queue *q, int len);
int q_isFull(queue q);
int q_isEmpty(queue q);
void q_enqueue(queue *q, int x);
int q_dequeue(queue *q);
void q_display(queue q);

