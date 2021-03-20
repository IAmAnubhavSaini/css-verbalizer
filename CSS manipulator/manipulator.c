/* copyright 2013-onwards Anubhav Saini
 * github.com/IAmAnubhavSaini
 * project: github.com/IAmAnubhavSaini/css-verbalizer
 *
 * purpose
 * -------
 * this is header for tokenizer functionality
 *
 * Licence
 * -------
 * MIT
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "tokenizer.h"

int main(int argc, char *argv[]){
  if(argc==2){
    token_printer(tokenizer(*(argv+1)));
    //rule_printer(ruleizer(*(argv+1)));
  }
}
