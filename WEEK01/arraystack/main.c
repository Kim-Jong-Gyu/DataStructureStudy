#include "arraystack.h"

int main()
{
    int max = 6;
    ArrayStack *arr;
	ArrayStackNode node;
    ArrayStackNode *peek;

    arr = createArrayStack(max);
    
    for (int i = 0; i < max ; i++)
    {
        node.data = i;
        pushAS(arr,node);
    }
    displayArrayStack(arr);
    printf("currentElementCount -> %d\n",arr->currentElementCount);
    popAS(arr);
    displayArrayStack(arr);
    printf("After Pop currentElementCount -> %d\n",arr->currentElementCount);
    peekAS(arr);
    printf("After Peek currentElementCount -> %d\n",arr->currentElementCount);
    displayArrayStack(arr);
}