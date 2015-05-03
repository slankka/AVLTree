#include "AVLTree.h" 
#include <stdio.h>  
#include <stdlib.h>  
    
  void InOrder(AvlTree T)  
  {  
      if(T != NULL)  
      {  
          InOrder(T->Left);  
          printf("%d ", T->Element);  
          InOrder(T->Right);  
      }  
  }  
    
  void PreOrder(AvlTree T)  
  {  
      if(T != NULL)  
      {  
          printf("%d ", T->Element);  
          PreOrder(T->Left);  
          PreOrder(T->Right);  
      }  
  }  
    
  int main(void)  
  {  
      AvlTree T;  
      Position P;  
      int i;  
    
      T = MakeEmpty(NULL);  
      for(i = 1; i <= 7; i++)  
          T = Insert(i, T);  
      for(i = 16; i >= 10; i--)   
          T = Insert(i, T);  
      T = Insert(8, T);  
      T = Insert(9, T);  
      printf("Root: %d\n", T->Element);  
      printf("InOrder:  ");  
      InOrder(T);  
      printf("\nPreOrder: ");  
      PreOrder(T);  
      putchar('\n');  
      system("Pause");  
    
      return 0;  
  }  