#include <stdlib.h>
#include "stack.h"

Stack createStack()
{

	Stack stack;

	stack.head = NULL;
	stack.tail = NULL;

	return stack;

}

int isEmpty(Stack *stack)
{
	return stack->head == NULL;
}

int getLength(Stack *stack)
{
	
	Node *node = stack->head;
	int length = 0;

	while (node != NULL)
	{
		length++;
		node = node->next; 
	}

	return length;

}

void push(Stack *stack, Board board, int depth, int isMaximizing)
{

	Node *node = malloc(sizeof(Node));
	
	node->board = board;
	node->depth = depth;
	node->isMaximizing = isMaximizing;
	
	if (isEmpty(stack))
		stack->tail = node;

	node->next = stack->head;
	stack->head = node;

}

Board pop(Stack *stack)
{

	Node *node = stack->head;
	Board board = node->board;

	stack->head = node->next;
	free(node);

	return board;

}
