#include "arraystack.h"

// 시간 복잡도 -> O(1)
// Stack을 개념 : 한 쪽 끝에서만 자료를 넣고 뺄 수 있는 LIFO(Last In First Out) 형식의 자료 구조
// Stack 예시 : 웹 브라우저 방문기록 (뒤로 가기) : 가장 나중에 열린 페이지부터 다시 보여준다.

ArrayStack* createArrayStack(int maxElementCount)
{
    if(maxElementCount < 0)
        return (NULL);
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
    ArrayStackNode *pop_node = NULL;
    pop_node = &(pStack->pElement[pStack->currentElementCount - 1]);
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