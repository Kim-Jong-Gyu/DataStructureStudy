#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

typedef struct ListNodeType
{
	int coef;
    int degree;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	ListNode headerNode;
} LinkedList;

LinkedList* createLinkedList();
int addPolyNodeLast(LinkedList* pList, float coef, int degree);
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
void displayLinkedList(LinkedList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif