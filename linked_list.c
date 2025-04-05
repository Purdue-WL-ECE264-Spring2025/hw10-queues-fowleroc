#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) { return NULL; }

void insert_at_head(struct linked_list *list, size_t value) {
  struct list_node *new = malloc(sizeof(struct list_node));
  new->value = value;
  new->next = list->head;
  list->head = new;
}

void insert_at_tail(struct linked_list *list, size_t value) {
  struct list_node *new = malloc(sizeof(struct list_node));
  new->value = value;
  new->next = NULL;
  if (list->head == NULL){
    list->head == new;
  }
  else{
    struct list_node *curr = list->head;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = new;
  }
}

size_t remove_from_head(struct linked_list *list) { 
  struct list_node *unwanted = list->head;
  list->head = unwanted->next;
  return 0; 
}

size_t remove_from_tail(struct linked_list *list) { 
  if (list->head->next == NULL){
    list->head = NULL;
  }
  else{
    struct list_node *curr = list->head;
    while(curr->next !=NULL){
      curr = curr->next;
    }
    curr->next = NULL;
  }
  return 0; 
}

void free_list(struct linked_list list) {
  struct list_node *curr = list.head;
  while(curr !=NULL){
    struct list_node *nextNode = curr->next;
    free(curr);
    curr = nextNode;
  }
  list.head = NULL;
  free(&list);
}


// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
