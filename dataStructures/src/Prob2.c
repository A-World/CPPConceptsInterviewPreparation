#include"General.h"


/* Probelm 2 : Maintain Linked List Tail Pointers  
	Head and Tail are global pointers to first and last element respectively, 
	of a singly linkedlist of integers. Implement C functions for the 
	following prototypes:

	bool remove (Element *elem);
	bool insertAfter(Element * elem, int data); 

	The argument to remove is the element to be deleted. The two arguments
	to insertAfter give the data for the new element and the element
	after which the new element is to be inserted. It should be possible to
	insert at the beginning of the list by calling insertAfter with NULL as
	the element argument. These functions should return true if successful
	and false is unsuccessful.
	Your functions must keep the head and tail pointers current.
*/

// We'll use same SSL with defined in General.h, with integers data

void Prob2()
{
	SLLNode *StartNode;
	SLLNode **Tail, **Head;
	CreateLinkedList(&StartNode);
}