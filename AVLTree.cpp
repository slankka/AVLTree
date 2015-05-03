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
	else if(X<T->Element)//�����������½ڵ�
	{
		T->Left=Insert(X,T->Left);
		if(Height (T->Left)-Height(T->Right)==2)//����������ڵ����Ը߶�������������������
		{
			if(X<T->Left->Element)
				T=SingleRotateWithLeft(T);//�� �� ������ӵ�����������һ�β��룬��Ҫ����
			else
                 T = DoubleRotateWithLeft(T); //�� �� ������ӵ�����������һ�β��룬��Ҫ˫��  

		}
	}
	else if(X > T->Element)//�����������½ڵ�
	{
		T->Right=Insert(X,T->Right);
		if(Height(T->Right) -Height(T->Left) == 2)
		{
			if(X < T->Left->Element)//�� �� ���Ҷ��ӵ�����������һ�β��룬��Ҫ����   
				T=SingleRotateWithRight(T);
			else //�� �� ���Ҷ��ӵ�����������һ�β��룬��Ҫ˫��
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

static Position DoubleRotateWithLeft(Position K3) //������ӵ����������в������ת
{
	K3->Left=SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);

}

static Position DoubleRotateWithRight(Position K3)//���Ҷ��ӵ����������в������ת
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
