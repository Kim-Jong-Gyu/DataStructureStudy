#ifndef _MAZE_STACK_
#define _MAZE_STACK_

typedef struct MapPositionType
{
    int x;
    int y;
} MapPosition;

typedef struct StackNodeType
{
	int flag;
    char direction; // 오른쪽 : 'r', 왼쪽 : 'l', 위쪽 : 't' , 아래쪽 : 'b'
	struct MapPosition* data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pTopElement;	    // Top 노드의 포인터
} LinkedStack;

#include <stdio.h>
#include <stdlib.h>

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void displayLinkedStack(LinkedStack* pStack);
void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]); 
void printMaze(int mazeArray[HEIGHT][WIDTH]);


#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_
#define HEIGHT      10
#define WIDTH       10

#define TRUE		1
#define FALSE		0

#endif