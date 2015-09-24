#include"General.h"

bool CreateLinkedList(SLLNode ** Start)
{
	*Start = NULL;
	return true;
#if 0 
	SLLNode *Head = (SLLNode *)malloc(sizeof(SLLNode));
	if (!Head)
	{
		DEGBUG_MEM_FAIL("Failed to allocated memory by malloc");
		return Head;
	}
	else
	{
		Head->data = data;
		Head->nextNode = NULL;
		return Head;
	}
#endif 
}

void PrintLinkeList(SLLNode * LinkedListID)
{
	printf("\n\n\n\n Printing content of linked list \n");
	int count = 1;

	if (LinkedListID)
	{
		while (LinkedListID->nextNode)
		{
			printf("SLLNode %d is %s\n", count, (char*)(LinkedListID->data));
			count++;
			LinkedListID = LinkedListID->nextNode;
		}
		printf("SLLNode %d is %s\n", count, (char*)(LinkedListID->data));
	}
}

bool AddNodeToLinkedList(SLLNode * LinkedListID, void *data)
{
	SLLNode *temp = LinkedListID;
	while (temp->nextNode)
	{
		temp = temp->nextNode;
	}


	DEBUG_INFO("temp = %p\n", temp);

	SLLNode *newNode = (SLLNode *)malloc(sizeof(SLLNode));
	if (!newNode)
	{
		DEGBUG_MEM_FAIL("Failed to allocated memory by malloc");
		return 0;
	}
	else
	{
		newNode->data = data;
		newNode->nextNode = NULL;
		temp->nextNode = newNode;
		return 1;
	}
}

bool DeleteNodeToLinkedList(SLLNode * LinkedListID, void *data)
{
	SLLNode *temp = LinkedListID;
	SLLNode *prevNode = LinkedListID;
	while (temp->nextNode)
	{

		// Check if strings are same
		printf("(char*)data = %s\n", (char*)data);
		printf("(char*)temp->data = %s\n", (char*)temp->data);
		if (!strcmp((char*)data, (char*)(temp->data)))
		{
			prevNode->nextNode = temp->nextNode;
			free(temp);
			temp = NULL;
			printf("Node deleted successfully");
			return;
			// Node found
		}
		else
		{
			// Previous node
			prevNode = temp;
			temp = temp->nextNode;
		}
	}
}

