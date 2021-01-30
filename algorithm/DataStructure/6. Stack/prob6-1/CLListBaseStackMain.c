#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "CLinkedList.h"

int main()
{
    Stack stack;
    StackInit(&stack);

    SPush(&stack, 11);
    SPush(&stack, 22);
    SPush(&stack, 33);
    SPush(&stack, 44);
    SPush(&stack, 55);

    while (!SIsEmpty(&stack))
        printf("%d ", SPop(&stack));

    return 0;
}