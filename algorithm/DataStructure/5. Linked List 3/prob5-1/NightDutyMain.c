#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "CLinkedList.h"
#include "Employee.h"

int main()
{
    CList list;
    int data, i, nodeNum, dutyDays;
    Emp *emp, *nightduty;
    ListInit(&list);

    /*Insert 4 employees*/
    emp = (Emp *)malloc(sizeof(Emp));
    emp->empNum = 1;
    strcpy(emp->ename, "Kevin");
    LInsert(&list, emp);

    emp = (Emp *)malloc(sizeof(Emp));
    emp->empNum = 2;
    strcpy(emp->ename, "Ryu");
    LInsert(&list, emp);

    emp = (Emp *)malloc(sizeof(Emp));
    emp->empNum = 3;
    strcpy(emp->ename, "Kim");
    LInsert(&list, emp);

    emp = (Emp *)malloc(sizeof(Emp));
    emp->empNum = 4;
    strcpy(emp->ename, "Choo");
    LInsert(&list, emp);

    /*Print all results list*/
    printf("\nWorkers list\n");
    if (LFirst(&list, &emp))
    {
        printf("%d  ", emp->empNum);
        printf("%s\n", emp->ename);
        for (i = 0; i < LCount(&list) - 1; i++)
        {
            if (LNext(&list, &emp))
            {
                printf("%d  ", emp->empNum);
                printf("%s\n", emp->ename);
            }
        }
    }
    printf("\n");

    /*return nightduty in 7 days*/
    dutyDays = 7;
    nightduty = WhoIsNightDuty(&list, nightduty, dutyDays);
    printf("\nnight duty in %d days : %d   %s\n", dutyDays,
           nightduty->empNum, nightduty->ename);
}