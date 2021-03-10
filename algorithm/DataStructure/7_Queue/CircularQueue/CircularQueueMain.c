#include <stdio.h>
#include "CircularQueue.h"

int main()
{
    // Queue Initialization
    Queue q;
    QueueInit(&q);

    // Insert data
    Enqueue(&q,1);
    Enqueue(&q,2);
    Enqueue(&q,3);
    Enqueue(&q,4);
    Enqueue(&q,5);

    // Data pull off
    while(!QIsEmpty(&q))
        printf("%d ", Dequeue(&q));
    
    return 0;
}