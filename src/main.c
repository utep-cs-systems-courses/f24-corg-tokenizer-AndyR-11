#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

#define MAX_STR_LENGTH 100
int main() {
  char str[MAX_STR_LENGTH];
  
  printf("Hello, enter some text or 'e'  to exit\n");
  
  while(1) {
    printf("> ");
    
    if(fgets(str, 100, stdin) != NULL) {
      if (str[0] == 'e') {
	break;
      }
      printf("You entered: %s\n", str);
    }
    else {
      break;
    }
  }

  printf("Program exited.\n");
  return 0;
}
