#include "linkedstack.h"

int main()
{
    int max = 6;
    LinkedStack *arr;
	StackNode node;
    StackNode *peek;

    arr = createLinkedStack(max);
    
    for (int i = 0; i < max ; i++)
    {
        node.data = i;
        pushLS(arr,node);
    }
    displayLinkedStack(arr);
    popLS(arr);
    displayLinkedStack(arr);
}