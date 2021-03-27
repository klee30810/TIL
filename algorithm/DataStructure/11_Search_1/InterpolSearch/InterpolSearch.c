#include <stdio.h>

int ISearch(int ar[], int first, int last, int target)
{
    int mid;

    if(first > last)
        return -1;      // -1의 반환은 탐색의 실패를 의미
    
    
    // 이진 탐색과의 차이점 반영
    mid = ((double)(target-ar[first])/ (ar[last]-ar[first]) * (last-first)) + first;

    if(ar[mid] == target)
        return mid;             // 탐색된 타겟의 인덱스 값 반환
    else if(target < ar[mid])
        return ISearch(ar, first, mid-1, target);
    else
        return ISearch(ar, mid+1, last, target);
}

int main()
{
    int idx, arr[] = {1,3,5,7,9};
    
    idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
    if(idx == -1)
        printf("Search Failure! \n");
    else    
        printf("target save index: %d \n", idx);
    
    idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 10);
    if(idx == -1)
        printf("Search Failure! \n");
    else
        printf("target save index: %d \n", idx);

    return 0;
}