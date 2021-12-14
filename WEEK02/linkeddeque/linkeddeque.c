#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
    LinkedDeque *pDeque;
    pDeque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
    if (pDeque == NULL)
        return (NULL);
    pDeque->currentElementCount = 0;
    pDeque->pFrontNode = NULL;
    pDeque->pRearNode = NULL;
    return(pDeque);
}
int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
    if(pDeque == NULL)
        return (0);
    if(isLinkedDequeFull(pDeque))
        return (0);
    DequeNode *new_node;
    new_node = (DequeNode *)malloc(sizeof(DequeNode));
    if(new_node == NULL)
        return (0);
    *new_node = element;
    if(pDeque->currentElementCount == 0)
    {
        pDeque->pFrontNode = new_node;
        pDeque->pRearNode = new_node;
    }
    else
    {
        pDeque->pFrontNode->pLLink = new_node;
        new_node->pRLink = pDeque->pFrontNode; 
        pDeque->pFrontNode = new_node;
    }
    pDeque->currentElementCount++;
    return(0);
}
int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
    if(pDeque == NULL)
        return (0);
    if(isLinkedDequeFull(pDeque))
        return (0);
    DequeNode *new_node;
    new_node = (DequeNode *)malloc(sizeof(DequeNode));
    if (new_node == NULL)
        return (0);
    *new_node = element;
    if(pDeque->currentElementCount == 0)
    {
        pDeque->pFrontNode = new_node;
        pDeque->pRearNode = new_node;
    }
    else
    {
        pDeque->pRearNode->pRLink = new_node;
        new_node->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = new_node;
    }
    pDeque->currentElementCount++;
    return (0);
}
DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
    if(pDeque == NULL)
        return (NULL);
    if(isLinkedDequeEmpty(pDeque))
        return (NULL);
    DequeNode *ret_node;
    ret_node = pDeque->pFrontNode;
    pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    ret_node->pRLink = NULL;
    if(pDeque->currentElementCount == 1)
        pDeque->pRearNode = NULL;
    else
        pDeque->pFrontNode->pLLink = NULL;
    pDeque->currentElementCount--;
    return(ret_node);
}
DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
    if(pDeque == NULL)
        return (NULL);
    if(isLinkedDequeEmpty(pDeque))
        return (NULL);
    DequeNode *ret_node;
    ret_node = pDeque->pRearNode;
    pDeque->pRearNode = pDeque->pRearNode->pLLink;
    ret_node->pLLink = NULL;
    if(pDeque->currentElementCount == 1)
        pDeque->pFrontNode = NULL;
    else
        pDeque->pRearNode->pRLink = NULL;
    pDeque->currentElementCount--;
    return(ret_node);    
}
DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    if(pDeque == NULL)
        return (NULL);
    if(isLinkedDequeEmpty(pDeque))
        return (NULL);
    DequeNode *ret_node;
    ret_node = pDeque->pFrontNode;
    return(ret_node);
}
DequeNode* peekRearLD(LinkedDeque* pDeque)
{
    if(pDeque == NULL)
        return (NULL);
    if(isLinkedDequeEmpty(pDeque))
        return (NULL);
    DequeNode *ret_node;
    ret_node = pDeque->pRearNode;
    return(ret_node);
}
void deleteLinkedDeque(LinkedDeque* pDeque)
{
    if (pDeque == NULL)
		return;
	for (int i = 0; i < pDeque->currentElementCount; i++)
	{
        deleteFrontLD(pDeque);
	}
	free(pDeque);
}
int isLinkedDequeFull(LinkedDeque* pDeque)
{
    return (FALSE);
}
int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    if (pDeque->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void displayLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *node;

	if (!pDeque)
		return;
	node = pDeque->pFrontNode;
	for (int i = 0; i < pDeque->currentElementCount; ++i)
		printf("====");
	printf("\n");
	for (int i = 0; i < pDeque->currentElementCount; ++i)
	{
		printf("%c ", node->data);
		node = node->pRLink;
	}
	printf("\n");
	for (int i = 0; i < pDeque->currentElementCount; ++i)
		printf("====");
	printf("\n");
}