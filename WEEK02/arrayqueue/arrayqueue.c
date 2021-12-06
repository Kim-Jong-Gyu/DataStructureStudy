#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
    if (maxElementCount <= 0)
        return (NULL);
    ArrayQueue *pQueue;
    pQueue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    if(pQueue == NULL)
        return (NULL);
    pQueue->currentElementCount = 0;
    pQueue->front = 0;
    pQueue->rear = 0;
    pQueue->maxElementCount = maxElementCount;
    pQueue->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
    if(pQueue->pElement == NULL)
    {
        free(pQueue);
        return (NULL);
    }
    return (pQueue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if(pQueue == NULL)
        return (0);
    if(isArrayQueueFull(pQueue))
        return (0);
    pQueue->pElement[pQueue->currentElementCount].data = element.data;
    pQueue->currentElementCount++;
    pQueue->rear++;
    return (0);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    if(pQueue == NULL)
        return (NULL);
    if(isArrayQueueEmpty(pQueue))
        return (NULL);
    ArrayQueueNode *result;
    result = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
    if (result == NULL)
        return (NULL);
    pQueue->pElement[pQueue->front].data = result->data;
    pQueue->currentElementCount--;
    pQueue->front++;
    return(result);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    if(pQueue == NULL)
        return (NULL);
    if(isArrayQueueEmpty(pQueue))
        return (NULL);
    ArrayQueueNode *result;
    result = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
    if (result == NULL)
        return (NULL);
    pQueue->pElement[pQueue->front].data = result->data;
    return(result);
}
void deleteArrayQueue(ArrayQueue* pQueue)
{
    if(pQueue == NULL)
        return ;
    free(pQueue->pElement);
    free(pQueue);
}
int isArrayQueueFull(ArrayQueue* pQueue)
{
    if(pQueue->currentElementCount == pQueue->maxElementCount)
        return (TRUE);
    return (FALSE);
}
int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    if(pQueue->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void displayArrayQueue(ArrayQueue* pQueue)
{
	if (!pQueue)
		return ;
	for (int i = 0; i < pQueue->currentElementCount; ++i)
		printf("====");
	printf("\n");
	for (int i = 0; i < pQueue->currentElementCount; ++i)
	{
		printf("[%c] ", pQueue->pElement[i].data);
	}
	printf("\n");
	for (int i = 0; i < pQueue->currentElementCount; ++i)
		printf("====");
	printf("\n");
}

