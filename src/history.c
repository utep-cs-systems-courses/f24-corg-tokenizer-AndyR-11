#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {
  List *tokenHistory = (List *)malloc(sizeof(List));

  if(tokenHistory) {
    tokenHistory->root = NULL;
  }
  return tokenHistory;
}

void add_history(List *list, char *str) {
  static int nodeID = 1;

  Item *node = (Item *)malloc(sizeof(Item));
  if(node == NULL) {
    printf("Memory allocation failed\n");
    return;
  }

  int len = 0;
  while(str[len] != '\0') {
    len++;
  }

  //Allocate memory for new string
  node->str = (char *)malloc(sizeof(char) * (len + 1));
  if(node->str == NULL) {
    printf("Memory allocation failed\n");
    free(node);
    return;
  }

  for(int i = 0; i < len; i++) {
    node->str[i] = str[i];
  }
  node->str[len] = '\0';

  node->id = nodeID++;
  node->next = NULL;

  if(list->root == NULL) {
    list->root = node;
  }
  else {
    Item *current = list->root;
    while(current->next) {
      current = current->next;
    }
    current->next = node;
  }
}

char *get_history(List *list, int id) {
  Item *current = list -> root;

  while(current) {
    if(current -> id == id) {
      return current -> str; 
    }
    current = current -> next;
  }
  printf("item not found\n");
  return '\0';
}

void print_history(List *list) {
  if(!list) {
    printf("No recorded history, enter sentences to tokenize\n");
  }

  Item *current = list -> root;

  while(current) {
    printf("%d: %s\n", current -> id, current -> str);
    current = current -> next;
  }
  printf("\n");
}

void free_history(List *list) {
  Item *current = list -> root;

  while(current) {
    Item *next = current -> next;
    free(current->str);
    free(current);
    current = next;
  }
  free(list);
}
