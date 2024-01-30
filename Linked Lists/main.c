#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

struct node{
	int ID;
	float arrival;
	float land;
	struct node* next;
};
typedef struct node airplane;

airplane queue[MAX_STACK_SIZE];
int front = -1;
int rear = -1;

airplane* insertNode(airplane*, int, float, float);
airplane* deletq(airplane*);
airplane* searchNode(airplane*, int);
void printList(airplane*);
void queueFull();
void queueEmpty();

int main() {
	printf("Airport Landing Simulation");
	airplane* first;
	first = NULL;
	airplane *current=NULL;

	while (1)
	{
		printf("Enter an action:\n");
		printf("a:arrival   l:landing   s:searching   p:printing   q:quit\n");
		char action;
		scanf_s(" %c", &action);
		airplane plane;


		if (action == 'a') {

			printf("Plane ID = ");
			scanf_s("%d", &plane.ID);
			printf("Arrival time = ");
			scanf_s("%f", &plane.arrival);
			printf("Landing time interval requirement = ");
			scanf_s("%f", &plane.land);
			if (first == NULL) {
				current = insertNode(first, plane.ID, plane.arrival, plane.land);
				first = current;
				//printf("first:%d\n", current->ID);
			}
			else {
				current = insertNode(current, plane.ID, plane.arrival, plane.land);
				//printf("second:%d\n", current->ID);
			}

			printf("Plane ID %d arrives at %.6f.\n", plane.ID, plane.arrival);
		}

		else if (action == 'l') {
			first = deletq(first);
		}

		else if (action == 's') {
			int id = 0;
			printf("Enter plane ID = ");
			scanf_s("%d", &id);
			airplane* search;
			search = searchNode(first, id);
			if (search == NULL)
				printf("The plane ID is not found in the list.\n");
			else
				printf("Plane ID = %d\nArrival time = %.6f\nLanding time interval requirement = %.6f\n", search->ID, search->arrival, search->land);			
		}

		else if (action == 'p') {
			printList(first);
		}

		else if (action == 'q') {
			exit(EXIT_SUCCESS);
		}
	}


	return 0;
}

void printList(airplane* first) {
	airplane* node;
	node = first;
	if (first == NULL)
		printf("List is empty!\n");
	else {
		while (node != NULL) {
			printf("Plane ID = %d, Arrival time = %.6f, Landing time interval requirement = %.6f\n", node->ID, node->arrival, node->land);
			node = node->next;
		}
		//printf("\n");
	}
}

airplane* searchNode(airplane *first,int id) {
	airplane* node = first;
	while (node != NULL) {
		if (node->ID == id)
			return node;
		else
			node = node->next;
	}
	return NULL;
}

airplane *deletq(airplane *first) {
	airplane* ptr = first;
	if (front == rear)
		queueEmpty();
	front = (front + 1) % MAX_STACK_SIZE;
	printf("Plane ID %d is landing at %.6f.\n", queue[front].ID, queue[front].arrival + queue[front].land);
	ptr = first->next;
	free(first);

	return ptr;
}

airplane *insertNode(airplane *first,int id,float a,float l) {
	rear = (rear + 1) % MAX_STACK_SIZE;
	if (rear == front) {
		queueFull();
	}

	else {
		airplane* newnode;

		if (first == NULL) {
			first = (airplane*)malloc(sizeof(airplane));
			first->ID = id;
			first->arrival = a;
			first->land = l;
			first->next = NULL;
			queue[rear] = *(first);
			return first;
		}
		else {
			newnode = (airplane*)malloc(sizeof(airplane));
			newnode->ID = id;
			newnode->arrival = a;
			newnode->land = l;
			newnode->next = first->next;
			queue[rear] = *(newnode);
			first->next = newnode;
			return newnode;
		}
	}

}

void queueFull() {
	fprintf(stderr, "Queue is full, cannot add element");
	exit(EXIT_FAILURE);
}

void queueEmpty() {
	fprintf(stderr, "Queue is empty, cannot pop element");
	exit(EXIT_FAILURE);
}