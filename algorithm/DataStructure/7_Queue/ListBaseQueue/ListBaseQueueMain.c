#include <stdio.h>
#include "ListBaseQueue.h"

int main()
{
    // Queue Initialization
    Queue q;
    QueueInit(&q);

    // data insert
    Enqueue(&q,1);
    Enqueue(&q,2);
    Enqueue(&q,3);
    Enqueue(&q,4);
    Enqueue(&q,5);

    // data Dequeue
    while(!QIsEmpty(&q))
    {
        printf("%d ", Dequeue(&q));
    }

    return 0;
}