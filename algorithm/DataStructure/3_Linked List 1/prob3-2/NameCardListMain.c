#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard *pcard;
	ListInit(&list);

	printf("1. 총 3명의 전화번호를 앞서 구현한 리스트에 저장한다.\n");
	pcard = MakeNameCard("홍길동", "010-4567-1234");
	LInsert(&list, pcard);
	pcard = MakeNameCard("김철수", "010-8564-1234");
	LInsert(&list, pcard);
	pcard = MakeNameCard("이영희", "010-1523-7561");
	LInsert(&list, pcard);

	printf("2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.");

	// 탐색 : "이경민"
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "홍길동"))
			ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			if (!NameCompare(pcard, "홍길동"))
				ShowNameCardInfo(pcard);
		}
	}

	printf("3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호를 변경한다.");
	// 탐색 : "이경민"
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "홍길동"))
			ChangePhoneNum(pcard, "010-1234-1234");
		while (LNext(&list, &pcard))
		{
			if (!NameCompare(pcard, "홍길동"))
				ChangePhoneNum(pcard, "010-1234-1234");
		}
	}

	printf("\n4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다.");
	// 탐색 : "이경민"
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "홍길동"))
			pcard = LRemove(&list);
		free(pcard);
		while (LNext(&list, &pcard))
		{
			if (!NameCompare(pcard, "홍길동"))
				pcard = LRemove(&list);
			free(pcard);
		}
	}

	// Print all people's list
	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}

	return 0;
}