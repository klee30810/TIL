#include "NameCard.h"

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּҰ� ��ȯ
NameCard *MakeNameCard(char *name, char *phone)
{
	NameCard *newCard = (NameCard *)malloc(sizeof(NameCard));
	strcpy(newCard->name, name);
	strcpy(newCard->phone, phone);

	return newCard;
}

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard *pcard)
{
	printf("\nname:  %s \n", pcard->name);
	printf("\nphone: %s \n", pcard->phone);
}

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard *pcard, char *name)
{
	if (!strcmp(pcard->name, name)) // same name
		return 0;

	else // different name
		return 1;
}

// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard *pcard, char *phone)
{
	strcpy(pcard->phone, phone);
}