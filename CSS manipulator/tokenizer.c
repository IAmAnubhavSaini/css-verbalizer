t_node* tokenizer(char *file_name){
  FILE *fp = fopen(file_name, "r");
  int space_seen =0;
  char ch;
  t_node *start, *temp = (t_node*)malloc(sizeof(t_node)), *current;
  char tempStr[MaxCssTokenSize];
  int tempStrIndex = 0;
  temp->next = NULL;
  start = temp;
  current = temp;

  if(fp == NULL){
    return NULL;
  }
  else{
    while((ch=fgetc(fp))!=EOF){
      if(ch==' ')space_seen++; else space_seen=0;
      if(DYN_IsTokenBoundary(ch)){ 				//if it is a token boundary
        if(tempStrIndex>0){ 					//and we have a string, signalled by tempStrIndex's walk on the number line towards right
          tempStr[tempStrIndex] = '\0'; 		//then of course we need to finish building a token
          strcpy(temp->token_name, tempStr);
          current = temp;
          //re-initialize
          temp = (t_node *)malloc(sizeof(t_node));
          temp->next = NULL;
          current->next = temp;
          tempStrIndex = 0;
        }
      }
      else{
        if(space_seen<=1){ 						//space_seen==0 means inside a token already, 1 means first char of token.
          tempStr[tempStrIndex++] = ch;
        }
      }
    }
  }
  return start;
}

void token_printer(t_node *start){
  t_node *current = start;
  while(current->next!=NULL){
    printf("\n%s",current->token_name );
    current = current->next;
  }
}