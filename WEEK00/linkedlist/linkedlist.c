#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *createLinkedList()
{
	LinkedList *ls = (LinkedList *)malloc(sizeof(LinkedList));

	if (ls == NULL)
		return (NULL);
	ls->head = NULL;
	ls->currentElementCount = 0;
	return (ls);
}
int addLLElement(LinkedList *pList, int position, ListNode element)
{
	if (position >= 0 && position <= pList->currentElementCount)
	{
		ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
		*newNode = element;
		newNode->pLink = NULL;
		ListNode *preNode = &(pList->headerNode);
		for (int i = 0; i < position; i++)
		{
			preNode = preNode->pLink;
		}
		newNode->pLink = preNode->pLink;
		preNode->pLink = newNode;
		pList->currentElementCount++;
	}
	else
	{
		fprintf(stderr, "Invalid access\n");
		exit(1);
	}
	return (TRUE);
}	
int removeLLElement(LinkedList *pList, int position)
{
	ListNode *next;
	ListNode *node;

	if (!pList)
		return (FALSE);
	if (pList->currentElementCount == 0)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	node = &(pList->headerNode);
	for (int i = 0; i < position - 1; i++)
	{
		node = node->pLink;
	}
	next = node->pLink;
	node->pLink = next->pLink;
	pList->currentElementCount--;
	free(next);
	return (TRUE);
}

ListNode *getLLElement(LinkedList *pList, int position)
{
	ListNode *ret;

	if (!pList)
		return (NULL);
	if (position < 0 || position > pList->currentElementCount)
		return (NULL);
	ret = &(pList->headerNode);
	for (int i = 0; i < position; i++)
	{
		ret = ret->pLink;
	}
	return (ret);
}

void clearLinkedList(LinkedList *pList)
{
	ListNode *node;

	if (!pList)
		return;
	node = &(pList->headerNode);
	for (int i = 0; i < pList->currentElementCount; ++i)
	{
		node->data = 0;
		node = node->pLink;
	}
}

int getLinkedListLength(LinkedList *pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList *pList)
{
	if (!pList)
		return;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		removeLLElement(pList, 0);
	}
	free(pList);
}

void displayLinkedList(LinkedList *pList)
{
	ListNode *node;

	if (!pList)
		return;
	node = &(pList->headerNode);
	for (int i = 0; i < pList->currentElementCount; ++i)
		printf("====");
	printf("\n");
	for (int i = 0; i < pList->currentElementCount; ++i)
	{
		printf("%d ", node->data);
		node = node->pLink;
	}
	printf("\n");
	for (int i = 0; i < pList->currentElementCount; ++i)
		printf("====");
	printf("\n");
}

void reverseLinkedList(LinkedList *pList)
{
	ListNode *node;
	ListNode *currentNode;
	ListNode *prevNode;

	if (pList == NULL)
		return;
	node = pList->headerNode.pLink;
	while (node != NULL)
	{
		prevNode = currentNode;
		currentNode = node;
		node = node->pLink;
		currentNode->pLink = pPrevNode;
	}
	pList->headerNode.pLink = pCurrentNode;
}
