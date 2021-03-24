#include <stdio.h>
#include <stdlib.h>

#include "ListBaseQueue.h"

void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL)
        return TRUE;
    else 
        return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if(QIsEmpty(pq))        // 1st node addition
    {
        pq->front = newNode;    // front points newnode
        pq->rear = newNode;     // rear points newnode
    }
    else                    // over 2nd node addition
    {
        pq->rear->next = newNode;   // last node points newnode
        pq->rear = newNode;         // rear points newnode
    }
}
Data Dequeue(Queue * pq)
{
    Node * delNode;
    Data retData;

    if(QIsEmpty(pq))
    {
        printf("Queue Memory Empty\n");
        exit(-1);
    }

    delNode = pq->front;    // save delnodne position
    retData = delNode->data; // save delnode data
    pq->front = pq->front->next; // front points next node of delnode

    free(delNode);
    return retData;
}

Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue empty!!\n");
        exit(-1);
    }

    return pq->front->data;
}