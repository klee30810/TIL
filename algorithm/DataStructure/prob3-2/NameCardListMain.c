#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard *pcard;
	ListInit(&list);

	printf("1. �� 3���� ��ȭ��ȣ�� �ռ� ������ ����Ʈ�� �����Ѵ�.\n");
	pcard = MakeNameCard("ȫ�浿", "010-4567-1234");
	LInsert(&list, pcard);
	pcard = MakeNameCard("��ö��", "010-8564-1234");
	LInsert(&list, pcard);
	pcard = MakeNameCard("�̿���", "010-1523-7561");
	LInsert(&list, pcard);

	printf("2. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ ����Ѵ�.");

	// Ž�� : "�̰��"
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "ȫ�浿"))
			ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			if (!NameCompare(pcard, "ȫ�浿"))
				ShowNameCardInfo(pcard);
		}
	}

	printf("3. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ��ȭ��ȣ�� �����Ѵ�.");
	// Ž�� : "�̰��"
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "ȫ�浿"))
			ChangePhoneNum(pcard, "010-1234-1234");
		while (LNext(&list, &pcard))
		{
			if (!NameCompare(pcard, "ȫ�浿"))
				ChangePhoneNum(pcard, "010-1234-1234");
		}
	}

	printf("\n4. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ �����Ѵ�.");
	// Ž�� : "�̰��"
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "ȫ�浿"))
			pcard = LRemove(&list);
		free(pcard);
		while (LNext(&list, &pcard))
		{
			if (!NameCompare(pcard, "ȫ�浿"))
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