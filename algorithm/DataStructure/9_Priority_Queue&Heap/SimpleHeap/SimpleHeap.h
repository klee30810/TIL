#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE    1
#define FALSE   0

#define HEAP_LEN    100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
    Priority pr;        // The lower pr, the higher Priority
    HData data;
} HeapElem;

typedef struct _heap
{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph);
int HIsEmpty(Heap * ph);

int GetParentIDX(int idx);
int GetLChildIDX(int idx);
int GetRChildIDX(int idx);

int GetHiPriChildIDX(Heap * ph, int idx);
void HInsert(Heap * ph, HData data, Priority pr);
HData HDelete(Heap * ph);

#endif