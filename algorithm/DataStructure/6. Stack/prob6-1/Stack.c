#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"
#include "CLinkedList.h"

void StackInit(Stack *pstack)
{
    pstack->list = (List *)malloc(sizeof(List));
    ListInit(pstack->list);
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->list->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    LInsertFront(pstack->list, data);
}

Data SPop(Stack *pstack)
{
    Data rdata;

    if (LFirst(pstack->list, &rdata))
    {
        rdata = LRemove(pstack->list);
        return rdata;
    }
    else
    {
        printf("no data in the stack!!\n");
        exit(-1);
    }
}

Data SPeek(Stack *pstack)
{
    Data data;
    LFirst(pstack->list, &data);

    return data;
}