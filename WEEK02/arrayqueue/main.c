#include "arrayqueue.h"

int main()
{
    ArrayQueue *arr;
	ArrayQueueNode node;

    arr = createArrayQueue(6);
    node.data = 'a';
    enqueueAQ(arr,node);
    node.data = 'b';
    enqueueAQ(arr,node);
    node.data = 'c';
    enqueueAQ(arr,node);
    node.data = 'd';
    enqueueAQ(arr,node);
    node.data = 'e';
    enqueueAQ(arr,node);
    node.data = 'f';
    enqueueAQ(arr,node);
    displayArrayQueue(arr);
    printf("%d\n",isArrayQueueFull(arr));
    dequeueAQ(arr);
    displayArrayQueue(arr);
}