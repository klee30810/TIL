#ifndef __STACK_H__
#define __STACK_H__

#define TRUE 1
#define FALSE 0

#include "CLinkedList.h"

typedef struct _listStack
{
    List *list;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif