#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

typedef struct ArrayHeapNodeType
{
	int key;
} ArrayHeapNode;

typedef struct ArrayHeapType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	ArrayHeapNode *pElement;	// 노드 저장을 위한 1차원 배열 포인터
} ArrayHeap;

#include <stdio.h>
#include <stdlib.h>

ArrayHeap* createArrayHeap(int maxElementCount);
int insertHeap(ArrayHeap *pHeap, ArrayHeapNode element);
ArrayHeapNode *deleteHeap(ArrayHeap *pHeap);
void deleteArrayHeap(ArrayHeap* pHeap);
int isArrayHeapFull(ArrayHeap* pHeap);
int isArrayHeapEmpty(ArrayHeap* pHeap);

#endif

#ifndef _COMMON_HEAP_DEF_
#define _COMMON_HEAP_DEF_

#define TRUE		1
#define FALSE		0

#endif