#include <stdio.h>
#include "Deque.h"

int main()
{
    // Deque Initialzation
    Deque deq;
    DequeInit(&deq);

    // 1st Data Insert
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveFirst(&deq));
    printf("\n");

    // 2nd Data Insert
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveLast(&deq));

    return 0;
}