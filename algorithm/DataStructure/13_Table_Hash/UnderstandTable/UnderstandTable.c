#include <stdio.h>

typedef struct _empInfo
{
    int empNum;         // 고유번호
    int age;            // 나이
} EmpInfo;

int main()
{
    EmpInfo empInfoArr[1000];
    EmpInfo ei;
    int eNum;

    printf("Enter empnum & age: ");
    scanf("%d %d", &(ei.empNum), &(ei.age));
    empInfoArr[ei.empNum] = ei;         

    printf("Enter the empnum to search: ");
    scanf("%d", &eNum);

    ei = empInfoArr[eNum];
    printf("empnum: %d, age: %d \n", ei.empNum, ei.age);
    return 0;
}