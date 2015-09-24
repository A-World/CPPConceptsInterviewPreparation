
#include"General.h"


// Added sample change to test svn checkings

int main()
{
#if 0
	SLLNode *StartNode;
	char LinkedListName[] = "Nodeabcd1";

	if (StartNode = CreateLinkedList((void *)(LinkedListName)))
	{
		printf("Linked list created successfully with name %s \n", (char *)(StartNode->data));
	}
	else
	{
		printf("Failed to create Linked list\n");
	}
	PrintLinkeList(StartNode);
	AddNodeToLinkedList(StartNode, "Ashish1");
	AddNodeToLinkedList(StartNode, "Ashish2");
	AddNodeToLinkedList(StartNode, "Ashish3");
	AddNodeToLinkedList(StartNode, "Ashish4");
	AddNodeToLinkedList(StartNode, "Ashish5");
	AddNodeToLinkedList(StartNode, "Ashish6");
	PrintLinkeList(StartNode);
	printf("Deleting node\n");
	DeleteNodeToLinkedList(StartNode, "Ashish4");
	PrintLinkeList(StartNode);
	getch();
#endif

#if 1 
	StackElement *myStack;
	void * data;
	createStack(&myStack);
	push(&myStack, (void*)"Stack Element 1 ");
	push(&myStack, (void*)"Stack Element 2 ");
	push(&myStack, (void*)"Stack Element 3 ");
	push(&myStack, (void*)"Stack Element 4 ");
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	push(&myStack, (void*)"Stack Element 5 ");
	push(&myStack, (void*)"Stack Element 6 ");
	push(&myStack, (void*)"Stack Element 7 ");
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);

	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);
	pop(&myStack, &data);
	printf("			Popping data from stack :::: data = %s\n", (char*)data);

	push(&myStack, (void*)"Stack Element 1 ");
	push(&myStack, (void*)"Stack Element 2 ");
	push(&myStack, (void*)"Stack Element 3 ");

	//printf("Now playing with the stack data structures\n");
#endif

	Prob2();


}

