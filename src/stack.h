#ifndef STACK_H
#define STACK_H

#include "board.h"

typedef struct Node Node;

typedef struct Node
{
	Board board;
	short int depth;
	short int isMaximizing;
	Node *next;	
} Node;

typedef struct Stack
{
	Node *head;
	Node *tail;
} Stack;

Stack createStack();
int isEmpty(Stack *stack);
int getLength(Stack *stack);
void push(Stack *stack, Board data, int depth, int isMaximizing);
Board pop(Stack *stack);
void emptyStack(Stack *stack);

#endif
