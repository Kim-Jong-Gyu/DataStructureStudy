#include "mazestack.h"

LinkedStack *createLinkedStack()
{
    LinkedStack *pStack;

    pStack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (pStack == NULL)
        return (NULL);
    pStack->currentElementCount = 0;
    pStack->pTopElement = NULL;
    return (pStack);
}

int pushLS(LinkedStack *pStack, StackNode element)
{
    StackNode *newNode;

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

StackNode *popLS(LinkedStack *pStack)
{
    StackNode *popNode;

    if (!pStack)
        return (NULL);
    if (isLinkedStackEmpty(pStack))
        return (NULL);
    popNode = pStack->pTopElement;
    pStack->pTopElement = pStack->pTopElement->pLink;
    pStack->currentElementCount--;
    return (popNode);
}

StackNode *peekLS(LinkedStack *pStack)
{
    if (!pStack)
        return (NULL);
    if (isLinkedStackEmpty(pStack))
        return (NULL);
    return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack *pStack)
{
    if (!pStack)
        return;
    for (int i = 0; i < pStack->currentElementCount; i++)
    {
        popLS(pStack);
    }
    free(pStack);
}

int isLinkedStackFull(LinkedStack *pStack)
{
    return (FALSE);
}

int isLinkedStackEmpty(LinkedStack *pStack)
{
    if (pStack->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void displayLinkedStack(LinkedStack *pStack)
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

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
    StackNode node;
    // 첫 시작은 0,0으로 시작하는걸 기본으로 한다는 전제
    if (pStack == NULL)
        return;
    node = (StackNode *)malloc(sizeof(StackNode));
    if (node == NULL)
        return;
    while (TRUE)
    {
        // 오른쪽으로 가는 경우의 수
        if (mazeArray[startPos.y + 1][startPos.x] == 1 && mazeArray[startPos.y][startPos.x + 1] == 0)
        {
            node.direction = 'r';
            node.data->x = startPos.x;
            node.data->y = startPos.y;
            pStack->pTopElement = node;
            startPos.x++;
        }
        // 아래쪽으로 가는 경우의 수
        if (mazeArray[startPos.y][startPos.x + 1] == 1 && mazeArray[startPos.y + 1][startPos.x] == 0)
        {
            node.direction = 'b';
            node.data->x = startPos.x;
            node.data->y = startPos.y;
            pStack->pTopElement = node;
            startPos.y++;
        }
    }
}
