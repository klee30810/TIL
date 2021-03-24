#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left];  // pivot위치는 가장 왼쪽
    int low = left+1;       
    int high = right;

    while(low <= high)      // 교차되지 않을 때까지 반복
    {
        // 피벗보다 큰 값을 찾는 과정
        while(pivot > arr[low])
            low++;

        // 피벗보다 작은 값을 찾는 과정
        while(pivot < arr[high])
            high--;

        // 교차되지 않으면 swap 실행
        if(low <= high)
            Swap(arr, low, high);
    }

    Swap(arr, left, right);
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if(left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}

int main()
{
    int arr[7] = {3,2,4,1,7,6,5};
    // int arr[3] = {3,3,3};

    int i, len = sizeof(arr)/sizeof(int);

    QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(i=0; i<len; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}