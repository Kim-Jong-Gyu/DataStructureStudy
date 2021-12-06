#include "linkeddeque.h"

int main()
{
    LinkedDeque *arr;
	DequeNode node;


    arr = createLinkedDeque();
    node.data = 'a';
    insertFrontLD(arr,node);
    printf("%d\n", arr->currentElementCount);
    node.data = 'b';
    insertRearLD(arr,node);
    printf("%d\n", arr->currentElementCount);
    node.data = 'c';
    insertFrontLD(arr,node);
    node.data = 'd';
    insertFrontLD(arr,node);
    node.data = 'e';
    insertFrontLD(arr,node);
    node.data = 'f';
    insertRearLD(arr,node);
    displayLinkedDeque(arr);
    deleteFrontLD(arr);
    displayLinkedDeque(arr);
    deleteRearLD(arr);
    displayLinkedDeque(arr);
}