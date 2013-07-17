t_node* tokenizer(char *file_name){
  FILE *fp = fopen(file_name, "r");
  int space_seen =0;
  char ch;
  t_node *start, *temp = (t_node*)malloc(sizeof(t_node)), *current;
  char tempStr[MaxTokenSize];
  int tempStrIndex = 0;
  temp->next = NULL;
  start = temp;
  current = temp;
  if(fp == NULL){
    return;
  }
  else{
    while((ch=fgetc(fp))!=EOF){
      if(ch==' ')space_seen++; else space_seen=0;
      if(IsTokenBoundary(ch)){
        if(tempStrIndex>0){
          tempStr[tempStrIndex] = '\0';
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
        if(space_seen<=1){
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