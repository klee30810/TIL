#include "SimpleHeap.h"

void HeapInit(Heap * ph)
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)
{
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx)
{
    return idx/2;
}

int GetLChildIDX(int idx)
{
    return idx*2;
}

int GetRChildIDX(int idx)
{
    return GetLChildIDX(idx) + 1;
}

// 두 개의 자식 노드 중 높은 우선ㅅ누위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap * ph, int idx)
{
    // 자식 노드가 없다면
    if(GetLChildIDX(idx) > ph->numOfData)
    {
        return 0; 
    }

    // 자식 노드가 왼쪽 노드 하나만 존재한다면
    else if(GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    
    // 자식 노드가 둘다 존재한다면
    else
    {
        // 오른쪽 우선순위가 높다면
        if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        // 왼쪽 우선순위가 높다면
        else   
            return GetLChildIDX(idx);
    }
}

// 데이터 저장
void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = ph->numOfData+1;
    HeapElem nelem = {pr, data};

    // 새 노드가 저장될 위치가 루트 노드의 위치가 아니라면 while 반복
    while(idx != 1)
    {
        // 새 노드와 부모노드 우선순위 비교
        if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
        {
            // 부모 노드를 한 레벨 내림
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];

            // 새 노드를 한 레벨 올림 -> 실제는 인덱스 값만 갱신
            idx = GetParentIDX(idx);
        }
        else 
            break;
    }

    ph->heapArr[idx] = nelem;
    ph->numOfData += 1;
}

// 데이터 삭제
HData HDelete(Heap * ph)
{
    HData retData = (ph->heapArr[1]).data;
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    // 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
    while(childIdx = GetHiPriChildIDX(ph, parentIdx))
    {
        if(lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 우선순위 비교
            break;

        // 마지막 노드보다 우선순위 높으니, 비교대상 노드의 위치를 한 레벨 올림
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;   // 마지막 노드 저장 위치정보를 한 레벨 내림
    }

    ph->heapArr[parentIdx] = lastElem; // 마지막 노드 최종 저장
    ph->numOfData -= 1;

    return retData;
}