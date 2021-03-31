#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

typedef struct _slot        // 구조체 Slot이 연결 리스트의 노드를 겸하는 구조
{
    Key key;
    Value val;
    struct _slot * next;        // 다음 노드를 가리키는 포인터 변수
} Slot;

#endif