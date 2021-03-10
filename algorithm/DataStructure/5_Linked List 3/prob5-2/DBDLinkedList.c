#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List *plist)
{
    // create dummy nodes
    plist->head = (Node *)malloc(sizeof(Node));
    plist->tail = (Node *)malloc(sizeof(Node));

    // connect two-way for head & tail nodes
    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->prev = plist->head;
    plist->tail->next = NULL;

    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    // create new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // two-way connection
    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;

    newNode->next = plist->tail;
    plist->tail->prev = newNode;

    // increase num of data
    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
    if (plist->head->next == plist->tail)
        return FALSE;

    plist->cur = plist->head->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List *plist, Data *pdata)
{
    if (plist->cur->next == plist->tail)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

Data LRemove(List *plist)
{
    Node *rpos = plist->cur;
    Data rdata = plist->cur->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;

    plist->cur = plist->cur->prev;

    free(rpos);
    (plist->numOfData)--;

    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}