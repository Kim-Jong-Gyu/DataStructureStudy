#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

DoublyList* createDoublyList()
{
    DoublyList *pReturn = (DoublyList*)malloc(sizeof(DoublyList));
    if (pReturn == NULL)
        reuturn(NULL);
    pReturn->currentElementCount = 0;
    return pList;
}

void deleteDoublyList(DoublyList* pList)
{
    if (!pList)
        return;
    clearDoublyList(pList);
    free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
    DoublyListNode  *new_node;
    DoublyListNode  *node;
    
    if (!pList)
        return (FALSE);
    if (position < 0 || position > pList->currentElementCount)
        return (FALSE);
    if (pList->currentElementCount == 0)
    {
        pList->headerNode = element;
        pList->currentElementCount++;
    }   
    node = &(pList->headerNode);
    for (int i = 0; i < position - 1; i++)
        node = node->pRLink;
    new_node = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    if(new_node == NULL)
        return (FALSE);
    new_node->data = element.data;
    new_node->pLLink = node;
    new_node->pRLink = node->pRLink;
    node->pRLink = new_node;
    new_node->pRLink->pLLink = new_node;
    pList->currentElementCount++;
    return(TRUE);
}

int removeDLElement(DoublyList *pList, int position)
{
    DoublyListNode *next;
    DoublyListNode *node;
    if (!pList)
        return (FALSE);
    if (position < 0 || position > pList->currentElementCount)
        return (FALSE);
    node = &(pList->headerNode);
    for (int i = 0; i < position - 1; i++)
        node = node->pRLink;
    next = node->pRLink;
    node->pRLink = next->pRLink;
    next->pRLink->pLLink = node;
    pList->currentElementCount--;
    free(next);
    return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
    if (!pList)
        return ;
     if (pList)
    {
        while (pList->currentElementCount != 0)
            removeDLElement(pList, 0);
    }
}

int getDoublyListLength(DoublyList *pList)
{
    if (!pList)
        return (-1);
    return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
    DoublyListNode *node;
    if (!pList)
        return (NULL);
    if (position < 0 || position > pList->currentElementCount)
        return (NULL);
    node = &(pList->headerNode);
    for (int i = 0; i < position; i++)
        node = node->pRLink;
    return (node);
}

void displayDoublyList(DoublyList *pList)
{
    DoublyListNode *currentNode;
    int length;

    length = pList->currentElementCount;
    if (pList = NULL || length == 0)
        return;
    printf("currentElementCount : %d", pList->currentElementCount);
    currentNode = &(pList->headerNode);
    for (int i = 0; i < length; i++)
    {
        currentNode = currentNode->pRLink;
        printf("{%d, %d}", i, currentNode->data);
    }
}





