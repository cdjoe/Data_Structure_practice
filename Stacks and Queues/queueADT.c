#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

//extern int rear;
//extern int front;

void addq(plane item) {
	//extern int rear;
	//extern int front;
	rear = (rear + 1) % MAX_STACK_SIZE;
	if (rear == front)
		queueFull();
	queue[rear] = item;
}

plane deleteq() {
	//extern int rear;
	//extern int front;
	if (front == rear)
		queueEmpty();
	front = (front + 1) % MAX_STACK_SIZE;
	return queue[front];
}

void queueFull() {
	fprintf(stderr, "Queue is full, cannot add element");
	exit(EXIT_FAILURE);
}

void queueEmpty() {
	fprintf(stderr, "Queue is empty, cannot pop element");
	exit(EXIT_FAILURE);
}