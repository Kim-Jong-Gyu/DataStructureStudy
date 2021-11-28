#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
    LinkedStack *pStack;

    pStack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if(pStack == NULL)
        return (NULL);
    pStack->currentElementCount = 0;
    pStack->pTopElement = NULL;
    return (pStack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
    StackNode *newNode;
    StackNode *preTop;

    if (!pStack)
        return (FALSE);
    newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode)
        return (FALSE);
    newNode->data = element.data;
    newNode->pLink = pStack->pTopElement;
    pStack->pTopElement = newNode;
    pStack->currentElementCount++;
    return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
    StackNode *popNode;

    if(!pStack)
        return (NULL);
    if (isLinkedStackEmpty(pStack))
        return (NULL);
    popNode = pStack->pTopElement;
    pStack->pTopElement = pStack->pTopElement->pLink;
    pStack->currentElementCount--;
    return (popNode);
}

StackNode* peekLS(LinkedStack* pStack)
{
    if(!pStack)
        return (NULL);
    if (isLinkedStackEmpty(pStack))
        return (NULL);
    return (pStack->pTopElement);    
}

void deleteLinkedStack(LinkedStack* pStack)
{
    if (!pStack)
		return;
	for (int i = 0; i < pStack->currentElementCount; i++)
	{
        popLS(pStack);
	}
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
    return(FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
    if (pStack->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void displayLinkedStack(LinkedStack* pStack)
{
	StackNode *node;

	if (!pStack)
		return;
	node = pStack->pTopElement;
	for (int i = 0; i < pStack->currentElementCount; ++i)
		printf("====");
	printf("\n");
	for (int i = 0; i < pStack->currentElementCount; ++i)
	{
		printf("%d ", node->data);
		node = node->pLink;
	}
	printf("\n");
	for (int i = 0; i < pStack->currentElementCount; ++i)
		printf("====");
	printf("\n");
}


