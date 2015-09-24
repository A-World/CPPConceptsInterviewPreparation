#include"stdio.h"
#include "conio.h"

/***  General macros ***/

#define bool unsigned char
#define true  1
#define false  0

#define DEGBUG_MEM_FAIL(...)		printf("Line %4d Func [%10s]  ", __LINE__,__FUNCTION__); printf(__VA_ARGS__);
#define DEBUG_INFO(...)				printf("Line %4d Func [%10s]  ", __LINE__,__FUNCTION__); printf(__VA_ARGS__);

/*****************************************************************************************************************************/
/***  SINGLY LINK LIST - DATA STRUCTURE ***/
typedef struct SLLNode
{
	struct SLLNode		*nextNode;
	void				*data;
}SLLNode;

// Singly linked list related Function declarations
bool		CreateLinkedList(SLLNode		** Start);
//bool		AddNodeToLinkedList(SLLNode		*LinkedListID, void		*data);
// Note in print function we have treated the element as character strings. One can custmize as per need and print it.
void		PrintLinkeList(SLLNode			*LinkedListID);

/*****************************************************************************************************************************/

/***  STACK - DATA STRUCTURE ***/
typedef struct StackElement
{
	struct StackElement			*next;
	void						*data;
}StackElement;

bool push(StackElement			**stack, void		*data);
bool pop(StackElement			**stack, void		**data);
bool createStack(StackElement	** stack);
bool deleteStack(StackElement	**stack);


