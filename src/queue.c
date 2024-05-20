#include <stdlib.h>
#include "queue.h"

Queue createQueue()
{

	Queue queue;

	queue.head = NULL;
	queue.tail = NULL;

	return queue;

}

int isEmpty(Queue *queue)
{
	return queue->head == NULL;
}

int getLength(Queue *queue)
{
	
	Node *node = queue->head;
	int length = 0;

	while (node != NULL)
	{
		length++;
		node = node->next; 
	}

	return length;

}

void insert(Queue *queue, Board data, int priority)
{

	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->priority = priority;
	
	// If queue is empty, no need to insert based on priority
	if (isEmpty(queue))
	{
		queue->head = node;
		queue->tail = node;
		return;
	}
	
	// Insert into queue based on priority
	Node *current = queue->head;
	Node *prev = NULL;
	
	while (current != NULL)
	{
	
		if (current->priority >= priority)
			break;	

		prev = current;
		current = current->next;
	
	}

	prev->next = node;
	node->next = current;

}

Board remove(Queue *queue)
{
	
	Board board = queue->tail->data;
	Node *node = queue->head;
	int length = getLength(queue);

	// If length of queue is 1, no need to set previous node to point to NULL (to avoid dangling pointer)
	if (length == 1)
	{
		queue->head = NULL;
		free(queue->head);
		return board;
	}
	
	while (node->next != queue->tail)
	{
		node = node->next;
	}

	node->next = NULL;
	free(queue->tail);

	return board;

}
