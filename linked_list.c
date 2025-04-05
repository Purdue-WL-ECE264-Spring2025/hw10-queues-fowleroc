#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) {
  struct list_node *node = malloc(sizeof(struct list_node));
  node->value = value;
  node->next = NULL;
  return node;
}

void insert_at_head(struct linked_list *list, size_t value) {
  struct list_node *new = new_node(value);
  if (list->head == NULL){
    list->head = new;
    return;
  }
  new->next = list->head;
  list->head = new;
}

void insert_at_tail(struct linked_list *list, size_t value) {
  struct list_node *new = new_node(value);
  new->next = NULL;

    struct list_node *curr = list->head;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = new;
  }


size_t remove_from_head(struct linked_list *list) {  
  if (list->head == NULL) return 0;
  struct list_node *unwanted = list->head;
  size_t val = unwanted->value;
  list->head = unwanted->next;
  free(unwanted);
  return val;
}

size_t remove_from_tail(struct linked_list *list) { 
  if (list->head == NULL) return 0;
  if (list->head->next == NULL) {
    size_t val = list->head->value;
    free(list->head);
    list->head = NULL;
    return val;
  }

  struct list_node *prev = NULL;
  struct list_node *curr = list->head;
  while (curr->next != NULL) {
    prev = curr;
    curr = curr->next;
  }

  size_t val = curr->value;
  free(curr);
  prev->next = NULL;
  return val;
} 


void free_list(struct linked_list list) {
  struct list_node *curr = list.head;
  while(curr !=NULL){
    struct list_node *nextNode = curr->next;
    free(curr);
    curr = nextNode;
  }
  list.head = NULL;
}


// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
