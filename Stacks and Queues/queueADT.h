#pragma once

#define MAX_STACK_SIZE 100

typedef struct {
	int ID;
	float arrival;
	float land;
} plane;

plane queue[MAX_STACK_SIZE];

extern int rear;
extern int front;

void queueFull(), queueEmpty();
plane deleteq();
void addq(plane item);