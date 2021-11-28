#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack *pStack = (ArrayStack *)malloc(sizeof(ArrayStack));
    if(pStack == NULL)
        return (NULL);
    pStack->currentElementCount = 0;
    pStack->maxElementCount = maxElementCount;
    pStack->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
    if (pStack->pElement == NULL)
    {
        free(pStack);
        return(NULL);
    }
    return (pStack);
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
    if(pStack == NULL)
        return (FALSE);
    if (isArrayStackFull(pStack))
        return(FALSE);
    pStack->pElement[pStack->currentElementCount].data = element.data;
    pStack->currentElementCount++;
    return (TRUE);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
    if (pStack == NULL)
        return (NULL);
    if (isArrayStackEmpty(pStack))
        return (NULL);
    ArrayStackNode *pop_node = (ArrayStackNode *)malloc(sizeof(ArrayStack));
    if(!pop_node)
        return (NULL);   
    *pop_node = pStack->pElement[pStack->currentElementCount - 1];
    pStack->currentElementCount--;
    return (pop_node);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
    if (!pStack)
        return (NULL);
    if (isArrayStackEmpty(pStack))
        return (NULL);
    ArrayStackNode *peek_node = NULL;
    peek_node = &(pStack->pElement[pStack->currentElementCount - 1]);
    return (peek_node);
}

void deleteArrayStack(ArrayStack* pStack)
{
    if (pStack == NULL)
		return ;
	free(pStack->pElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
    if(pStack->currentElementCount == pStack->maxElementCount)
        return (TRUE);
    return (FALSE);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
    if(pStack->currentElementCount == 0 || pStack->maxElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void displayArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		return ;
	for (int i = 0; i < pStack->currentElementCount; ++i)
		printf("====");
	printf("\n");
	for (int i = 0; i < pStack->currentElementCount; ++i)
	{
		printf("[%d] ", pStack->pElement[i].data);
	}
	printf("\n");
	for (int i = 0; i < pStack->currentElementCount; ++i)
		printf("====");
	printf("\n");
}