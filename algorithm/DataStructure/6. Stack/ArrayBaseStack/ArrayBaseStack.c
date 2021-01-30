#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack *pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack)
{
	Data rdata;

	if (SIsEmpty(pstack))
	{
		printf("No data in stack!!\n");
		exit(-1);
	}

	rdata = pstack->stackArr[pstack->topIndex];
	(pstack->topIndex)--;

	return rdata;
}

Data SPeek(Stack *pstack)
{
	Data rdata;

	if (SIsEmpty(pstack))
	{
		printf("No data in stack!!\n");
		exit(-1);
	}

	rdata = pstack->stackArr[pstack->topIndex];

	return rdata;
}
