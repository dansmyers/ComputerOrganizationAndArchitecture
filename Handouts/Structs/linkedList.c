// A linked list implementation
// DSM, 2016

#include <stdio.h>
#include <stdlib.h>


typedef struct listNode_t {
  int value;
  struct listNode_t *next;
} ListNode;

typedef struct linkedList_t {
  ListNode *head;
} LinkedList;


/*** Initialize a new list ***/
LinkedList * newLinkedList() {
  LinkedList *newList = malloc(sizeof(LinkedList));
  newList->head = NULL;

  return newList;
}


/*** Add a node to the front of a list ***/
void addToFront(LinkedList *list, int value) {
  
  // Allocate a new list node
  ListNode *newNode = malloc(sizeof(ListNode));
  
  // Set the newNode's value
  newNode->value = value;
  newNode->next = NULL;

  // Tie the new node onto the front of the list
  newNode->next = list->head;
  list->head = newNode;

  return;
}


/*** Print contents of a list ***/
void print(LinkedList *list) {
  ListNode *current = list->head;
  
  if (current == NULL) {
      printf("[]");
      return;
  }

  printf("[");
  while (current->next != NULL) {
    printf("%d, ", current->value);
    current = current->next;
  }
  printf("%d]\n", current->value);
  
  return;
}


int main() {
  LinkedList *list = newLinkedList();

  addToFront(list, 5);
  addToFront(list, 4);
  addToFront(list, 3);
  addToFront(list, 2);

  print(list);

  return 0;
}
