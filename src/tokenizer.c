#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c) {
  if ((c == ' ' || c == '\t') && c != '\0') {
    return 1;
  }
  return 0;
}

int non_space_char(char c) {
  if ((c == ' ' || c == '\t') || c == '\0') {
    return 0;
  }
  return 1;
}

char *token_start(char *str) {
  while(space_char(*str)) {
    str++;
  }

  if(*str == '\0') {
    return NULL;
  }

  if(non_space_char(*str)) {
    return str;
  }

  return NULL;
}

char *token_terminator(char *token) {
  while(non_space_char(*token)) {
    token++;
  }
  return token;
}

int count_tokens(char *str) {
  int count = 0;
  char *token = token_start(str);

  while(token != NULL) {
    count++;

    token = token_terminator(token);

    token = token_start(token);
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char *copyStr = (char *)malloc(sizeof(char) * (len + 1));

  int i;
  for (i = 0; i < len; i++) {
    copyStr[i] = inStr[i];
  }
  copyStr[i] = '\0';

  return copyStr;
}

char **tokenize(char* str) {
  int token_count = count_tokens(str);
  char **tokens = malloc(sizeof(char *) * (token_count + 1));

  int i = 0;
  char *token = token_start(str);
  while(token != NULL) {
    char *terminator = token_terminator(token);
    int length = terminator - token;
    tokens[i++] = copy_str(token, length);

    token = token_start(terminator);
  }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens) {
  for(int i = 0; tokens[i] != NULL; i++) {
    printf("tokens[%d] = %s\n", i, tokens[i]); 
  }
}

void free_tokens(char **tokens) { 
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
}

