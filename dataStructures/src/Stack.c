#include"General.h"
// Stack operations

// Stack contains a pointer to top

bool createStack(StackElement ** stack)
{
	*stack = NULL;
	return true;
}

bool push(StackElement **stack, void *data)
{
	StackElement *elem = (StackElement *)malloc(sizeof(StackElement));
	if (elem)
	{
		elem->data = data;
		elem->next = *stack;
		printf("Pushing data to stack :::: data = %s\n", (char*)elem->data);
		*stack = elem;
		return true;
	}
	else
	{
		DEGBUG_MEM_FAIL("Failed to allocated memory by malloc");
		return false;
	}
}
bool pop(StackElement **stack, void **data)
{
	StackElement *elem = *stack;
	if (elem)
	{
		*data = elem->data;
		*stack = elem->next;
		free(elem);
		return true;
	}
	else
	{
		*data = NULL;
		return false;
	}
}
bool deleteStack(StackElement **stack)
{
	StackElement *next;
	while (*stack)
	{
		next = (*stack)->next;
		free(stack);
		*stack = next;
	}
	return true;
}
