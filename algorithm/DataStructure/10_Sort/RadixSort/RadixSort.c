#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM  10

void RadixSort(int arr[], int num, int maxLen)
{
    // maxLen에는 가장 긴 데이터의 길이정보 전달
    Queue buckets[BUCKET_NUM];
    int bi, pos, di, divfac=1, radix;

    for(bi=0; bi<BUCKET_NUM; bi++)
        QueueInit(&buckets[bi]);

    // 가장 긴 데이터의 길이만큼 반복
    for(pos=0; pos<maxLen; pos++)
    {
        // 정렬 대상의 수만큼 반복
        for(di=0; di<num; di++)
        {
            // N번째 자리수 추출
            radix = (arr[di] / divfac) % 10;
            Enqueue(&buckets[radix], arr[di]);
        }

        // 버킷 수만큼 반복
        for(bi=0, di=0; bi<BUCKET_NUM; bi++)
        {
            // 버킷에 저장된 순서대로 다 꺼내서 다시 arr에 저장
            while(!QIsEmpty(&buckets[bi]))
                arr[di++] = Dequeue(&buckets[bi]);
        }

        divfac *= 10;
    }
}

int main()
{
    int arr[7] = {13,212,14,7141, 10987, 6, 15};
    int i, len = sizeof(arr)/sizeof(int);

    RadixSort(arr, len, 5);

    for(i=0; i<len; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}