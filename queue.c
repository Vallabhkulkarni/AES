#include "queue.h"
#include<stdlib.h>
#include<stdio.h>

void init_queue(queue *q, int len) {
	q->size = len;
	q->front = q->rear = -1;
	q->Q = (int*)malloc(sizeof(int) * len);
}

int q_isFull(queue q) {
	if(q.rear == q.size - 1) {
		return 1;
	}
	else return 0;
}

int q_isEmpty(queue q) {
	if(q.front == q.rear) {
		return 1;
	}
	else return 0;
}

void q_enqueue(queue *q, int x) {
	if(!q_isFull(*q)) {
		q->rear++;
		q->Q[q->rear] = x;
		return;
	}
}

int q_dequeue(queue *q) {
	int x = '0';
	if(!q_isEmpty(*q)) {
		q->front++;
		x = q->Q[q->front];
	}
	return x;
}


void q_display(queue q) {
	int i;
	printf("\n[");
	for(i = q.front + 1; i <= q.rear; i++) {
		printf("%d ", q.Q[i]);
	}
	printf("]\n");
	return;
}

