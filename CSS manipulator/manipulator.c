#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#include "token_DS.c"
#include "tokenizer.c"
int main(int argc, char *argv[]){
  if(argc==2){
    token_printer(tokenizer(*(argv+1)));
    //rule_printer(ruleizer(*(argv+1)));
  }
}