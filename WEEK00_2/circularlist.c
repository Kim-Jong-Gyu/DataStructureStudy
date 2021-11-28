#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* createLinkedList()
{
	LinkedList* ls = (LinkedList*)malloc(sizeof(LinkedList));
	
	if (ls == NULL)
		return (NULL);
	ls->currentElementCount = 0;
	return (ls);
}

void deleteCircularList(CircularList *pList)
{
    if (!pList)
        return;
    clearCircularList(pList);
    free(pList);
}

int addCLElement(CircularList *pList, int position, CircularListNode element)
{
    ListNode *node;
	ListNode *next;
	ListNode *add;
	
	if (!pList)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (pList->currentElementCount == 0)
	{
		pList->headerNode = 
		pList->currentElementCount++;
		return (TRUE);
	}
	node = &(pList->headerNode);
	for (int i = 0; i < position - 1; i++)
	{
		node = node->pLink;
	}
	add = (ListNode*)malloc(sizeof(ListNode));
	if (add == NULL)
		return (FALSE);
	*add = element;
    next = node->pLink;
	node->pLink = add;
	element.pLink = next;
	pList->currentElementCount++;
	return (TRUE);
}

