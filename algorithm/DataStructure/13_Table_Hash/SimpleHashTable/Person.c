#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person * p)
{
    return p->ssn;
}

void ShowPerInfo(Person * p)
{
    printf("ssn : %d \n", p->ssn);
    printf("name : %s \n", p->name);
    printf("addr : %s \n", p->addr);
    printf("\n");
}

Person * MakePersonData(int ssn, char * name, char * addr)
{
    Person * newP = (Person*)malloc(sizeof(Person));
    newP -> ssn = ssn;
    strcpy(newP->name, name);
    strcpy(newP->addr, addr);
    return newP;
}