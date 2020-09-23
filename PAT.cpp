#include <stdio.h>
#include <stdlib.h>
#include<queue>
#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

void show(List L){
	while(L!=NULL)
	{
		printf("%d  , ",L->Data);
		L=L->Next;
	}
	printf("\n");
}
int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    //show(L);
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find( List L, ElementType X )
{
  std::queue<int> test;
  while(L!=NULL)
  {
    if(L->Data==X)
    break;
    L=L->Next;
  }
  if(L==NULL)
    return ERROR;
  return L;
}
List Insert( List L, ElementType X, Position P )
{
    
    
  List before=L;
  //如果P在L处，没有before
  if(P==L)
  {
  Position tmp = (Position)malloc(sizeof(struct LNode));
  tmp->Data = X;
  tmp->Next = L;
  L = tmp;
  return L;
  }
  //找到P的前一个位置
  while(before!=NULL)
  {
    if(before->Next==P)
    break;
    before=before->Next;
  }
  //before没找到
  if(before==NULL)
  {
    printf("Wrong Position for Insertion");
    return ERROR;
  }
  //before找到了
  Position tmp = (Position)malloc(sizeof(struct LNode));
  tmp->Data = X;
  before->Next = tmp;
  tmp->Next = P;
  return L;
}
List Delete( List L, Position P )
{
  List before=L;
  //如果为空表
  if(L ==NULL &&P==NULL)
  {
      return L;
  }
  //删除头结点
  if(P==L)
  {
    List L1=L->Next;
    free(L);
    return L1;
  }
  //删除其他结点
  while(before!=NULL)
  {
    if(before->Next==P)
    break;
    before=before->Next;
  }
  if(before==NULL)
  {
    printf("Wrong Position for Deletion");
    return ERROR;
  }
  List c=before->Next;
  before->Next=c->Next;
  free(c);
  return L;
}
