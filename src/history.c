#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {
  List *tokenHistory = (List *)malloc(sizeof(List));

  tokenHistory -> root = NULL; //initialize the root to null
  return tokenHistory;
}

void add_history(List *list, char *str) {
  int nodeID = 1;
  Item *node = list -> root;

  while(node) {
    node = node -> next;
    nodeID++;
  }
  node = malloc(sizeof(Item));
  node -> id = nodeID;
  node -> str = str;
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
  Item *current = list -> root;

  while(current) {
    printf("%d: %s\n", current -> id, current -> str);
    current = current -> next;
  }
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
