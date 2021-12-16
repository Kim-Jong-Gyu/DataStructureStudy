#include "arrayheap.h"

// max heap 기준으로 작성했음
ArrayHeap* createArrayHeap(int maxElementCount)
{
    if(maxElementCount <= 0)
        return (NULL);
    ArrayHeap *pHeap;
    pHeap = (ArrayHeap *)malloc(sizeof(ArrayHeap));
    if(!pHeap)
        return (NULL);
    pHeap->currentElementCount = 0;
    pHeap->maxElementCount = maxElementCount;
    pHeap->pElement = (ArrayHeapNode *)malloc(sizeof(ArrayHeapNode) * maxElementCount);
    if(!pHeap->pElement)
        return (NULL);
    // 배열 첫칸은 비워 놓는다.
    pHeap->pElement[0].key = -1;
    return (pHeap);
}

int insertHeap(ArrayHeap *pHeap, ArrayHeapNode element)
{
    int i;

    if(!pHeap)
        return(FALSE);
    if (isArrayHeapFull(pHeap))
        return(FALSE);
    i = pHeap->currentElementCount + 1;
    while(i != 1 && element.key > pHeap->pElement[i/2].key)
    {
        pHeap->pElement[i] = pHeap->pElement[1/2];
        i = i/2;
    }
    pHeap->pElement[i] = element;
    pHeap->currentElementCount++;
    return (TRUE);
}

ArrayHeapNode *deleteHeap(ArrayHeap *pHeap)
{
    int parent;
    int child;
    ArrayHeapNode *result;
    ArrayHeapNode *tmp;
    
    parent = 1;
    child = 2;
    if(!pHeap)
        return(NULL);
    if(isArrayHeapEmpty(pHeap))
        return(NULL);
    *result = pHeap->pElement[parent];
    // 마지막 값 저장
    *tmp = pHeap->pElement[pHeap->currentElementCount];
    pHeap->pElement[parent] = pHeap->pElement[pHeap->currentElementCount];
    while(child <= pHeap->currentElementCount)
    {
        if(child < pHeap->currentElementCount && pHeap->pElement[child].key < pHeap->pElement[child + 1].key)
            child++;
        if(tmp->key >= pHeap->pElement[child].key)
            break;
        pHeap->pElement[parent] = pHeap->pElement[child];
        parent = child;
        child = child * 2;
    }
    pHeap->pElement[parent]= *tmp;
    pHeap->currentElementCount--;
    return (result);
}

int isArrayHeapFull(ArrayHeap* pHeap)
{
    if(pHeap->currentElementCount == pHeap->maxElementCount)
        return (TRUE);
    return (FALSE);
}

void deleteArrayHeap(ArrayHeap* pHeap)
{
    if(pHeap == NULL)
        return ;
    free(pHeap->pElement);
    free(pHeap);
}

int isArrayHeapEmpty(ArrayHeap* pHeap)
{
    if(pHeap->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}
