#include<stdio.h>
#include<stdlib.h>

struct NODE
{
  struct NODE *link;
  int value;
  int valid; /* set to 1 if valid */
};
typedef struct NODE Node;


int insertFirst(Node **ptrToHeadPtr, int val){
  Node* new_node = (Node*) malloc (sizeof(Node));
  new_node->value = val;
  new_node->valid = 1;
  new_node->link = (*ptrToHeadPtr);
  (*ptrToHeadPtr) = new_node;
  if(*ptrToHeadPtr == NULL){
    return 0;
  }else
    return 1;
}

void traverse(Node *ptrToHeadPtr)
{
  while(ptrToHeadPtr != NULL){
    if(ptrToHeadPtr->valid == 1){
      printf("%d ", ptrToHeadPtr->value );
    }
    ptrToHeadPtr = ptrToHeadPtr->link;
  }
}

void traverseAll(Node *ptrToFirst)
{
  while( ptrToFirst != NULL ){
    if(ptrToFirst->valid == 0){
      printf("*%d ", ptrToFirst->value );
    }else{
      printf("%d ", ptrToFirst->value );
    }
    ptrToFirst = ptrToFirst->link;
  }
}

int deleteFirst(Node *ptrToFirst){
  if(ptrToFirst == NULL)
  {
    return 0;
  }
  while(ptrToFirst != NULL){
    if(ptrToFirst->valid == 1){
      ptrToFirst->valid = 0;
      return 1;
    }
    ptrToFirst = ptrToFirst->link;
  }
  return 0;
}

int countNodes(Node *ptrToFirst){
  int count = 0;
  if(ptrToFirst == NULL)
  {
    return 0;
  }
  while(ptrToFirst != NULL){
    if(ptrToFirst->valid == 1){
      count++;
    }
    ptrToFirst = ptrToFirst->link;
  }
  return count;
}

int deleteLast(Node *ptrToFirst){
  if(ptrToFirst == NULL)
  {
    return 0;
  }
  int count = 0;
  Node* current = ptrToFirst;
  while(current != NULL)
  {
    count++;
    current = current->link;
  }
  for(int i=count; i>=1; i--){
    Node* curr = ptrToFirst;
    for(int k=0; k<i-1 && curr != NULL; k++){
      curr = curr->link;
    }
    if(curr != NULL && curr->valid == 1){
      curr->valid = 0;
      return 1;
    }
  }
}

int deleteValue(Node *ptrToFirst, int val){
  if(ptrToFirst == NULL)
  {
    return 0;
  }
  while(ptrToFirst != NULL){
    if(ptrToFirst->value == val && ptrToFirst->valid == 1){
      ptrToFirst->valid = 0;
      return 1;
    }
    ptrToFirst = ptrToFirst->link;
  }
  return 0;
}

int restoreValue(Node *start, int val){
  if(start == NULL)
  {
    return 0;
  }
  while(start != NULL){
    if(start->value == val && start->valid == 0){
      start->valid = 1;
      return 1;
    }
    start = start->link;
  }
  return 0;
}

int compact(Node *old, Node **ptrToNewHeadPtr) {
  if(old == NULL)
  {
    return 0;
  }
  while(old != NULL){
    if(old->valid == 1){
      Node* new_node = (Node*) malloc (sizeof(Node));
      new_node->value = old->value;
      new_node->valid = 1;
      new_node->link = *ptrToNewHeadPtr;
      *ptrToNewHeadPtr = new_node;
    }
    old = old->link;
  }
  if(*ptrToNewHeadPtr == NULL){
    return 0;
  }else
    return 1;
}

void freeList(Node *ptrToNewHeadPtr){
  Node *temp;
  while ( ptrToNewHeadPtr != NULL ){
    temp = ptrToNewHeadPtr;
    ptrToNewHeadPtr = ptrToNewHeadPtr->link;
    free( temp );
  }
}

int main(){
  Node *HeadPtr = NULL;
  Node *HeadPtr2 = NULL;
  int j;
  for (j=0; j<13; j++){
    insertFirst(&HeadPtr, j);
    insertFirst(&HeadPtr, j);
  }
  // insertFirst(&HeadPtr, 1);
  // insertFirst(&HeadPtr, 2);
  // insertFirst(&HeadPtr, 3);
  // insertFirst(&HeadPtr, 4);
  printf("\nDeletefirst returns %d \n",deleteFirst(HeadPtr));
  printf("\nDeletefirst returns %d \n",deleteFirst(HeadPtr));
  printf("\nDeletefirst returns %d \n",deleteFirst(HeadPtr));

  printf("\nDeleteLast returns %d \n",deleteLast(HeadPtr));
  printf("\nDeleteLast returns %d \n",deleteLast(HeadPtr));
  printf("\nDeleteLast returns %d \n",deleteLast(HeadPtr));
  printf("\nDeleteValue 12 returns %d \n",deleteValue(HeadPtr,12));
  printf("\nDeleteValue 9 returns %d \n",deleteValue(HeadPtr,9));
  printf("\nRestoreVale 10 returns %d \n",restoreValue(HeadPtr,10));
  printf("\nRestoreVale 12 returns %d \n",restoreValue(HeadPtr,12));
  traverseAll(HeadPtr);
  printf("\n");
  traverse(HeadPtr);
  printf("\ncompact returns %d \n",compact(HeadPtr, &HeadPtr2));
  printf("\n");
  // freeList(HeadPtr);
  traverseAll(HeadPtr);
  printf("\n");
  traverseAll(HeadPtr2);
  printf("\nThe number of valid node is %d ",countNodes(HeadPtr));
  printf("\nThe number of nodes in new node is %d ",countNodes(HeadPtr2));

}
