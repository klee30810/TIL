#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList의 생성 및 초기화 ***/
	List list;
	int data, sum = 0;
	ListInit(&list);

	/*** 9개의 데이터 저장 ***/
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	LInsert(&list, 9);

	/*** 1. 저장된 데이터의 전체 출력 ***/
	printf("1 현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}

	/*2. 리스트 값을 순차적으로 참조하여 그 합을 출력*/
	if (LFirst(&list, &data)) // 첫번째 데이터의 조회
	{
		sum += data;

		while (LNext(&list, &data)) // 두번째 이후의 데이터 조회
			sum += data;
		printf("\n current sum: %d\n", sum);
	}

	/*** 3. 리스트의 2의 배수와 3의 배수를 모두 삭제 ***/
	if (LFirst(&list, &data))
	{
		if ((data % 2 == 0) || (data % 3 == 0))
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if ((data % 2 == 0) || (data % 3 == 0))
				LRemove(&list);
		}
	}

	printf("3 현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}

	printf("\n\n");

	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("3, 4. 현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}