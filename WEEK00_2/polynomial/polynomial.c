#include "polynomial.h"

LinkedList *createLinkedList()
{
	LinkedList *ls = (LinkedList *)malloc(sizeof(LinkedList));

	if (ls == NULL)
		return (NULL);
	ls->head = NULL;
	ls->currentElementCount = 0;
	return (ls);
}

int getLinkedListLength(LinkedList *pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

int addLLElement(LinkedList *pList, int position, ListNode element)
{
	if (position >= 0 && position <= pList->currentElementCount)
	{
		ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
		*newNode = element;
		newNode->pLink = NULL;
		ListNode *preNode = &(pList->headerNode);
		for (int i = 0; i < position; i++)
		{
			preNode = preNode->pLink;
		}
		newNode->pLink = preNode->pLink;
		preNode->pLink = newNode;
		pList->currentElementCount++;
	}
	else
	{
		fprintf(stderr, "Invalid access\n");
		exit(1);
	}
	return (TRUE);
}	

int addPolyNodeLast(LinkedList* pList, float coef, int degree)
{
    int ret =FALSE;
    int i = 0;

    ListNode node = {0,};
    node.coef = coef;
    node.degree = degree;

    if(pList != NULL)
    {
        int length = getLinkedListLength(pList);
        ret = addLLElement(pList, length, node);
    }
    return ret;
}

void polyAdd(ListType *plist1, ListType *plist2, ListType *plist3)
{
    ListNode *tmp1 = plist1->head;
    ListNode *tmp2 = plist2->head;
    float sum;
 
    while (tmp1 && tmp2)
    {
        if (tmp1->degree == tmp2->degree)
        {
            sum = tmp1->coef + tmp2->coef;
            if (sum != 0) 
                addPolyNodeLast(plist3,sum,tmp1->degree);
            tmp1 = tmp1->plink;
            tmp2 = tmp2->plink;
        }
        else if (tmp1->degree > tmp2->degree)
        {
            addPolyNodeLast(plist3,tmp1->coef,tmp1->degree);
            tmp1 = tmp1->plink;
        }
        else
        {
            addPolyNodeLast(plist3,tmp2->coef,tmp2->degree);
            tmp2 = tmp2->link;
        }
    }
    // 나머지 부분 처리하는곳
    for (; tmp1 != NULL; tmp1 = tmp1->link)
        addPolyNodeLast(plist3,tmp1->coef,tmp1->expon);
    for (; tmp2 != NULL; tmp2 = tmp2->link)
        addPolyNodeLast(plist3,tmp2->coef,tmp2->expon);
}

void polyPrint(ListType *plist)
{
    ListNode *p = plist->head;
 
    printf("polynomial = ");
    for (; p != NULL; p = p->link)
        printf("%d^%d + ",p->coef,p->expon);
    printf("");
}
