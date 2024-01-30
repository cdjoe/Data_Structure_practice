#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

//int rear = -1;
//int front = -1;
rear = -1;
front = -1;

//typedef struct {
//	int key;
//} element;
//element stack[MAX_STACK_SIZE];
//int top = -1;
//
//void stackFull(),stackEmpty();
//element pop();
//void push(element item);

int main() {
	//printf("Stack operations\n");

	//while (1)
	//{
	//	printf("Enter an action:\n");
	//	printf("1: push 2: pop q: quit\n");
	//	char action;
	//	scanf_s(" %c", &action);

	//	if (action == '1') {
	//		element item;
	//		printf("Item to push = ");
	//		scanf_s("%d", &item.key);
	//		push(item);
	//	}
	//	else if (action == '2') {
	//		printf("Pop result = %d\n", pop().key);
	//	}
	//	else if(action=='q') {
	//		exit(EXIT_SUCCESS);
	//	}

	//}

	printf("Airport Landing Simulation");

	while (1)
	{
		printf("Enter an action:\n");
		printf("a: arrival       l: landing       q: quit\n");
		char action;
		scanf_s(" %c", &action);
		plane airplane;

		if (action == 'a') {

			printf("Plane ID = ");
			scanf_s("%d", &airplane.ID);
			printf("Arrival time = ");
			scanf_s("%f", &airplane.arrival);
			printf("Landing time interval requirement = ");
			scanf_s("%f", &airplane.land);
			addq(airplane);
			printf("Plane ID %d arrives at %.6f.\n", airplane.ID, airplane.arrival);
		}
		else if (action == 'l') {
			airplane = deleteq();
			printf("Plane ID %d is landing at %.6f.\n", airplane.ID, airplane.arrival + airplane.land);
		}

		else if (action == 'q') {
			exit(EXIT_SUCCESS);
		}


	}

	return 0;
}


//void push(element item) {
//	if (top >= MAX_STACK_SIZE - 1)
//		stackFull();
//	stack[++top] = item;
//}
//
//element pop() {
//	if (top == -1)
//		stackEmpty();
//	return stack[top--];
//}
//
//void stackFull() {
//	fprintf(stderr, "Stack is full, cannot add element");
//	exit(EXIT_FAILURE);
//}
//
//void stackEmpty() {
//	fprintf(stderr, "Stack is empty, cannot pop element");
//	exit(EXIT_FAILURE);
//}