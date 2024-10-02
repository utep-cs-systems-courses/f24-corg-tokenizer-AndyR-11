#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

#define MAX_LENGTH 100

int main() {
  char str[MAX_LENGTH];
  char input[10];
  char id[10];
  List *history = init_history();
  
  printf("Hello, welcome to the tokenizer.\n");
  
  while(1) {
    printf("Enter a 't' if you would like to tokenize a sentence, 'h' to get the history, '!' to tokenize a certain sentence from the history, or 'e' to exit\n");
    printf("> ");
    fgets(input, 100, stdin);

   switch(input[0]) {

    case 't' :
      printf("Please enter your sentence:\n>");
      fgets(str, 100, stdin);
      char **tokens = tokenize(str);
      printf("\n");
      add_history(history, str);
      print_tokens(tokens);
      free_tokens(tokens);
      break;

      
    case 'h':
      print_history(history);
      break;

      
   case '!':
     printf("Enter the id of the sentence you want to recall\n");
     fgets(id, 100, stdin);
     int pos = atoi(id);
     printf("Sentence at: %d recalled\n" ,pos);
     char **tempTokenize = tokenize(get_history(history, pos));
     print_tokens(tempTokenize);
     free_tokens(tempTokenize);
     break;

     
    case 'e':
      free_history(history);
      printf("\nClosing the program...\n");
      return 0;

      
    default:
      printf("Incorrect input, please try again\n");
      break;
      
   }
  }
     printf("Program exited.\n");
     return 0;
}
