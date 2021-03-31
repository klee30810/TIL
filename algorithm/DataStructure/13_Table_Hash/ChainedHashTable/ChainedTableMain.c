#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main()
{
    Table myTbl;
    Person * np, * sp, * rp;

    TBLInit(&myTbl, MyHashFunc);

    // Data Insert
    np = MakePersonData(900254, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900139, "Kim", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900827, "HAN", "Kangwon");
    TBLInsert(&myTbl, GetSSN(np), np);

    // Data Search
    sp = TBLSearch(&myTbl, 900254);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900139);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900827);
    if(sp != NULL)
        ShowPerInfo(sp);

    // Data Delete
    rp = TBLDelete(&myTbl, 900254);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 900139);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 900827);
    if(rp != NULL)
        free(rp);

    return 0;
}