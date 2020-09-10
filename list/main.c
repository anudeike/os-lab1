#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    struct node n1, n2, n3;
  struct node *head;
  struct list l1;

  n1.value = 92;
  n2.value = 182;
  n3.value = 341;

  

  //links values
  head = &n3;//sets head to n3
  n3.next = &n2; //connescts pointer n2 to head
  n2.next = &n1;
  n1.next= NULL; //this is where the list ends

  // add the first node as the head of the list
  l1.head = head;

  //work
  
  list_print(&l1);
  list_add_to_back(&l1, 5);

  //work 
  list_print(&l1);
  list_add_to_front(&l1, 18);

  //works
  list_print(&l1);
  list_add_at_index(&l1,90,2);
  list_print(&l1);

  //works 
  list_add_at_index(&l1,50,200);
  list_print(&l1);

  //works
  list_remove_from_back(&l1);
  list_print(&l1);

  list_remove_from_front(&l1);
  list_print(&l1);

  list_remove_at_index(&l1, 2);
  list_print(&l1);

  list_is_in(&l1, 90);
  list_is_in(&l1, 100);
  list_get_elem_at(&l1, 1); 

  // get the length 
  list_get_index_of(&l1,60);
   list_get_index_of(&l1,100);
  printf("\nLength: %d\n",list_length(&l1));

  // allocate for new list
  list_t* l2 = list_alloc();
  list_add_to_front(l2, 2);
  list_add_to_back(l2, 89);
  list_print(l2);
}