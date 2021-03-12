#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq) // 텅 빈 경우 front, rear은 동일위치
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == pq->rear) // empty
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)     // 큐의 다음 위치 인덱스 반환
{
    if(pos == QUE_LEN-1)    // 배열의 마지막 요소의 인덱스 값 이라면
        return 0;
    else
        return pos+1;
}

void Enqueue(Queue * pq, Data data)
{
    if(NextPosIdx(pq->rear) == pq->front)       // full
    {
        printf("Queue memory full\n");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear); // move rear to next 
    pq->queArr[pq->rear] = data;     // save at rear position
}

Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue empty\n");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);      // move front to next
    return pq->queArr[pq->front];           // return front position
}

Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Empty\n");
        exit(-1);
    }

    return pq->queArr[NextPosIdx(pq->front)];
}