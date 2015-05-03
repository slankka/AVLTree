#include "stdio.h"
#include "stdlib.h"
typedef int ElementType;  
	  
#ifndef _AVLTREE_H  
#define _AVLTREE_H  
	  
struct TreeNode  
{  
	ElementType Element;  
	int Height;  
	struct TreeNode *Left;  
	struct TreeNode *Right;  
};  
	  
typedef struct TreeNode *AvlTree;  
typedef struct TreeNode *Position;  
	  
AvlTree MakeEmpty(AvlTree T);  
AvlTree Insert(ElementType X, AvlTree T);  
Position Find(ElementType X ,AvlTree T);  
Position FindMax(AvlTree T);  
Position FindMin(AvlTree T); 

static int Height(Position P);

static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
void FatalError(char message[]);


#endif  
