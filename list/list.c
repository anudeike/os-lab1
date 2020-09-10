// list/list.c
// 
// Implementation for linked list.
//
// Ikechukwu Anude

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() { 

  //create newNode
  node_t newNode;

  // alloc space for the head
  node_t* head = (node_t *)malloc(sizeof(newNode));
  head->next = NULL;

  // init the new list
  list_t* newList;
  newList->head = head;
  return newList; 
}

void list_free(list_t *l) {
  node_t * temp = l->head;

  while(temp != NULL){
    // cycle thru, freeing each node at a time
    node_t * toFree = temp;
    temp = temp->next;
    free(toFree);
    toFree = NULL; // must do this to clear the data
  }
}

// prints all the values in the list
void list_print(list_t *l) {
  node_t * temp = l->head;

  while(temp != NULL){
    printf(" | %d | ", temp->value);
    temp = temp->next; // go to next value
  }
  printf("\n");
}

// gets the length of the list
int list_length(list_t *l) { 
  node_t * temp = l->head;
  int count = 0;
  while(temp != NULL){
    count++;
    temp = temp->next; // go to next value
  }
  printf("Length is: %d", count);
  return count;
}

void list_add_to_back(list_t *l, int value) {
  node_t * temp = l->head;

  // allocate memory first before adding new pointer
  node_t * newNode = (node_t*) malloc(sizeof(newNode));
  newNode->value = value;

  while(temp->next != NULL){
    temp = temp->next; // go to next value
  }

  temp->next = newNode;
  printf("\n");
}

void list_add_to_front(list_t *l, int value) {
  node_t *temp = l->head;// get the head
  node_t *newNode = (node_t*) malloc(sizeof(newNode)); // alloc
  newNode->value = value;//assigns new node to parameter
  newNode->next = temp; 
  l-> head = newNode;
}

void list_add_at_index(list_t *l, int value, int index) {
  node_t* temp = l->head;//head refernce
  node_t *newNode = (node_t*) malloc(sizeof(newNode));//a;llocates memory for new node
  newNode->value = value;//assigns new value to new node
  int count = 0;
  while(temp != NULL){//traveres list to add at index
    // if zero, then skip
    if(temp->value == 0){
      continue;
    }

    if (count == index-1){
      // the new node points to the head.next
      newNode->next = temp->next;
      
      // set the index to temp->next
      temp->next = newNode;
      return;
    }
    //printf("%d",count);
    count++;
    temp = temp->next;
  }

  // if we reach null then the index is not in the list and we cannot insert
  printf("Index out of bounds. Cannot insert\n");
}

int list_remove_from_back(list_t *l) { 
  node_t *temp = l->head;

  //traverse till end
  while(temp->next->next != NULL){
    temp = temp->next;
  }

  free(temp->next);//frees space
  temp->next = NULL;//sets space to null
  printf("\nnode is now deleted.\n");
  return 0;
}

int list_remove_from_front(list_t *l) { 
  node_t *temp = l->head;
  if(temp != NULL){ //traveres list
    l-> head = temp->next;
    printf("\n front node is now deleted.\n");
  }
  else{
    printf("\n Head node is NULL.\n");
  }
  return 0;
}

int list_remove_at_index(list_t *l, int index) {
  node_t* temp = l->head;
  int value = index;
  int count = 0;
  while(temp != NULL){
    // if zero, then skip
    if (count == value-1){
   // printf("Node at index ", value, "is deleted\n");
     temp->next = temp->next->next;
     printf("\nNode is deleted at index: %d\n",value);
    }
    //printf("%d",count);
    count++;
    temp = temp->next;
  }
  // if we reach null then the index is not in the list and we cannot insert
 // printf("Index out of bounds. Cannot insert\n");
  return 0; 
}

bool list_is_in(list_t *l, int value) {
  int target = value;
  node_t* t = l->head;
  while(t->next!= NULL){//traverses list
    if (t->value == target){
      printf("True\n");
      return true;
    }

    t = t->next;
  }

  printf("False\n");
  return false; 
}

int list_get_elem_at(list_t *l, int index){
  
  node_t* temp = l->head;//head refence
  int count = 0;
    while(temp->next != NULL){//traveres lsit
      if(index == count){
        printf("\nNode at index: %d\n",index);//print element at specific index
        printf(" is %d\n",temp->value);
        return temp->value;
      }
      count++; //increment the count
      temp = temp->next;
    }
    printf("\nIndex is out of bounds");
  return -1;
}

int list_get_index_of(list_t *l, int value) {
  int target = value;
  node_t* temp = l->head;//head refernce
  int count = 0;
    while(temp->next != NULL){//travereses list
      if(target == temp->value){
        printf("\nThe value of %d", value);//prints current index
        printf(" is in index %d\n",count);
        return temp->value;//retrurns value at index
      }
      count++; //increment the count
      temp = temp->next;
    }
     printf("\nValue %d",value);
     printf(" is not in list");
      
  return -1; 
}