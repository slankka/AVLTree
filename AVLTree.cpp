#include "AVLTree.h"
#include "stdio.h"
#include "malloc.h"

AvlTree MakeEmpty(AvlTree T){
if(T!=NULL){
	MakeEmpty(T->Left);
	MakeEmpty(T->Right);
	free(T);
}

return NULL;
}

static int Height(Position P)
{
	if(P==NULL)
		return -1;
	else
		return P->Height;
}

static int Max(int a,int b)
{
return a>b?a:b;
}
  
AvlTree Insert(ElementType X, AvlTree T){
	if (T==NULL)
	{
		T=(Position)malloc(sizeof(TreeNode));
		if(T==NULL)
			FatalError("Out of Space!");
		T->Element=X;
		T->Height=0;
		T->Left=T->Right=NULL;
	}
	else if(X<T->Element)//左子树插入新节点
	{
		T->Left=Insert(X,T->Left);
		if(Height (T->Left)-Height(T->Right)==2)//左子树插入节点所以高度是左子树高于右子树
		{
			if(X<T->Left->Element)
				T=SingleRotateWithLeft(T);//对 α 的左儿子的左子树进行一次插入，需要左旋
			else
                 T = DoubleRotateWithLeft(T); //对 α 的左儿子的右子树进行一次插入，需要双旋  

		}
	}
	else if(X > T->Element)//右子树插入新节点
	{
		T->Right=Insert(X,T->Right);
		if(Height(T->Right) -Height(T->Left) == 2)
		{
			if(X < T->Left->Element)//对 α 的右儿子的右子树进行一次插入，需要右旋   
				T=SingleRotateWithRight(T);
			else //对 α 的右儿子的左子树进行一次插入，需要双旋
				T=DoubleRotateWithRight(T);
		}
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
		return T;
}


static Position SingleRotateWithLeft(Position K2)
{
	Position K1=K2->Left;
	K2->Left=K1->Right;
	K1->Right=K2;

	K1->Height=Max(Height(K1->Left),Height(K1->Right)) +1;
	K2->Height=Max(Height(K2->Left),Height(K2->Right)) +1;
	
	return K1;
}

static Position SingleRotateWithRight(Position K2)
{
	Position K1=K2->Right;
	K2->Right=K1->Left;
	K1->Left=K2;

	K1->Height=Max(Height(K1->Left),Height(K1->Right)) +1;
	K2->Height=Max(Height(K2->Left),Height(K2->Right)) +1;
	return K1;

}

static Position DoubleRotateWithLeft(Position K3) //对左儿子的右子树进行插入的旋转
{
	K3->Left=SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);

}

static Position DoubleRotateWithRight(Position K3)//对右儿子的左子树进行插入的旋转
{
	K3->Right=SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);

}
Position Find(ElementType X ,AvlTree T)
{
	if(T==NULL)
		return NULL;
	if(X<T->Element)
		return Find(X,T->Left);
	else if(X>T->Element)
		return Find(X,T->Right);
	else
		return T;

}

Position FindMax(AvlTree T)
{
	if(T==NULL)
		return NULL;
	else if(T->Right ==NULL)
		return T;
	else 
		return FindMax(T->Right);

}
Position FindMin(AvlTree T)
{
	if(T==NULL)
		return NULL;
	else if(T->Left ==NULL)
		return T;
	else 
		return FindMin(T->Left);
	
}

void FatalError(char message[])
{
	printf("%s\n",message);
	getchar();
	exit(0);
}
