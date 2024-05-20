#ifndef QUEUE_H
#define QUEUE_H

#include "board.h"

typedef struct Node Node;

typedef struct Node
{
	Board data;
	Node *next;	
	int priority;
} Node;

typedef struct Queue
{
	Node *head;
	Node *tail;
} Queue;

Queue createQueue();
int isEmpty(Queue *queue);
int getLength(Queue *queue);
void insert(Queue *queue, Board data, int priority);
Board remove(Queue *queue);

#endif
