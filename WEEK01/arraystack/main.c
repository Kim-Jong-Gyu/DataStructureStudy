#include "arraystack.h"

int main()
{
	ArrayStack * pstack = NULL;
	ArrayStackNode element;
	ArrayStackNode* tmp;

	printf("createArrayStack 전의 pstack주소: %p\n", pstack);
	pstack = createArrayStack(6);
	printf("createArrayStack 후의 pstack주소: %p\n", pstack);
	printf("------------pstack------------\n");
	printf("maxElementCount: %d currentElementCount: %d pElement:%p\n", pstack->maxElementCount, pstack->currentElementCount, pstack->pElement);

	printf("\ntest\n");
	element.data = 'A';
	pushAS(pstack, element);
	
	element.data = 'B';
	pushAS(pstack, element);

	element.data = 'C';
	pushAS(pstack, element);
	displayArrayStack(pstack);

	tmp =peekAS(pstack);
	printf("%c\n",tmp->data);

	printf("isFULL? %d\n",isArrayStackFull(pstack));
	printf("isEMPTY? %d\n",isArrayStackEmpty(pstack));
	printf("\ntest\n");
	tmp = popAS(pstack);
	printf("%c\n",tmp->data);
	tmp = popAS(pstack);
	printf("%c\n",tmp->data);
	tmp = popAS(pstack);
	printf("%c\n",tmp->data);

	displayArrayStack(pstack);
	printf("isFULL? %d\n",isArrayStackFull(pstack));
	printf("isEMPTY? %d\n",isArrayStackEmpty(pstack));
	
	deleteArrayStack(pstack);
}