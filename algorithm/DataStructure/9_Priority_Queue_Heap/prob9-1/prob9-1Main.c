#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * str1, char * str2)
{
    return strlen(str2) - strlen(str2);
}

int main()
{
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    PEnqueue(&pq, "Hello! ");
    PEnqueue(&pq, "My name is");
    PEnqueue(&pq, "Kevin Lee!!!!");

    while(!PQIsEmpty(&pq))
        printf("%s" , PDequeue(&pq));

    return 0;
}