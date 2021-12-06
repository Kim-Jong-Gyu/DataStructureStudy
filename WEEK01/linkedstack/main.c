#include "linkedstack.h"

int main()
{
    LinkedStack *arr;
	StackNode node;
    StackNode *peek;

    arr = createLinkedStack();
    
    for (int i = 0; i < max ; i++)
    {
        node.data = i;
        pushLS(arr,node);
    }
    displayLinkedStack(arr);
    popLS(arr);
    displayLinkedStack(arr);
}