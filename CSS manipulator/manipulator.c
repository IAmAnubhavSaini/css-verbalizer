#include<stdio.h>
#include "tokenizer.c"

int main(int argc, char *argv[]){
  if(argc==2){
    token_printer(tokenizer(*(argv+1)));
  }
}