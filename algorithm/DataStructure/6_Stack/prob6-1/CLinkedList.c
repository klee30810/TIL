#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List *plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List *plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

void LInsert(List *plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->tail == NULL) // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->tail == NULL) // 저장된 노드가 없다면
	{
		printf("no data remaining");
		return FALSE;
	}

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List *plist)
{
	Node *rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail) // 삭제 대상을 tail이 가리킨다면
	{
		if (plist->tail == plist->tail->next) // 그리고 마지막 남은 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}

Data WhoIsNightDuty(List *plist, Data data, int days)
{
	int empnum, remainder;
	Data nightduty;

	empnum = LCount(plist);
	remainder = days % empnum;

	// need different type of data type. check chap5 problems
	//printf("current duty : %d  %s", plist->cur->data->empNum, plist->cur->data->ename);

	LFirst(plist, &data);
	for (int i = 0; i < remainder - 1; i++)
		LNext(plist, &data);

	nightduty = data;
	return nightduty;
}