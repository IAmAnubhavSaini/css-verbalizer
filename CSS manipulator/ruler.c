
t_node* ruleizer(char *file_name){
  FILE *fp = fopen(file_name, "r");
  int space_seen =0;
  int opened_brace=0;
  char ch;
  t_node *start, *temp = (t_node*)malloc(sizeof(t_node)), *current;
  char tempStr[MaxRuleSize];
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
      if(ch=='{') opened_brace++;
      if(ch=='}') opened_brace--;
      if(IsRuleBoundary(ch)){
        if(tempStrIndex>0){
          tempStr[tempStrIndex] = '\0';
          strcpy(temp->rule_name, tempStr);
          current = temp;
          //re-initialize
          temp = (t_node *)malloc(sizeof(t_node));
          temp->next = NULL;
          current->next = temp;
          tempStrIndex = 0;
        }

      }
      else{
        if(space_seen<=1){//skip if more than 1 consecutive space is seen
          if(opened_brace>0 && ch!='{'){//picking only the rules
            tempStr[tempStrIndex++] = ch;
          }
        }
      }
    }
  }
  return start;
}

void rule_printer(t_node *start){
  t_node *current = start;
  while(current->next!=NULL){
    printf("\n%s",current->rule_name);
    current = current->next;
  }
}