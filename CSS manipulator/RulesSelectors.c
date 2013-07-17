// CONSTANTS
#define RuleBoundaryCount 2
#define MaxRuleSize 100

// STATES
int OutsideBlock = 1;
int OutsideComment = 1;

// TYPES
typedef struct selector_node Selectors;
typedef struct rule_node Rules;
typedef struct meta_info Meta;
typedef enum element_type ElementType;

struct selector_node{
  char *Selector;
  Meta *Info;
  Rules *FirstRule;
  int RuleCount;
  struct selector_node *Next;
};

struct rule_node {
  char *Rule;
  Meta *Info;
  struct rule_node *Next;
};

struct meta_info{
  int LineNumber;
  char *Id;
  ElementType Type;
};

enum element_type{
  ET_UNKNOWN = 0,
  ET_RULE = 1,
  ET_SELECTOR = 2
};

// CONSTRAINTS
char rule_boundaries []= {';','\n'};
char selector_boundaries[] = {'{'};

// FUNCTION DEFINITIONS
Meta *create_meta(char *id, int lineNumber, ElementType type);
Meta *create_meta_minimum(int lineNumber);
char *generate_random_id(void);
Rules *create_rule(char *rule_str, Meta *info, Rules *next); //next tend to be NULL most of the time.
Selectors *create_selector(char *selector_str, Meta *info, Selectors *next);//next tend to be NULL most of the time.
Selectors *add_rule_to_selector(Rules *rule, Selectors *toThis);
// FUNCTION DECLARATIONS
Meta *create_meta(char *id, int lineNumber, ElementType type){
  Meta *info = (Meta*)malloc(sizeof(Meta));
  info->Id = id;
  info->LineNumber = lineNumber;
  info->Type = type;
  return Meta;
}
Meta *create_meta_minimum(int lineNumber){
  Meta *info = (Meta*)malloc(sizeof(Meta));
  info->Id = generate_random_id();
  info->LineNumber = lineNumber;
  info->Type = ET_UNKNOWN;
  return info;
}
char *generate_random_id(void){
  //TODO: implement some random string generation.
}
Rules *create_rule(char *rule_str, Meta *info, Rules *next){
  Rules *new_rule = (Rules*)malloc(sizeof(Rules));
  new_rule->Rule = rule_str;
  new_rule->Info = info;
  new_rule->Next = next;
  return new_rule;
}
Selectors *create_selector(char *selector_str, Meta *info, Selectors *next){
  Selectors *new_sel = (Selectors*)malloc(sizeof(Selectors));
  new_sel->Selector = selector_str;
  new_sel->FirstRule = (Rules*)malloc(sizeof(Rules));//is this really required?
  new_sel->FirstRule = NULL;
  new_sel->Info = info;
  new_sel->Next = next;
  return new_sel;
}
Selectors *add_rule_to_selector(Rules *rule, Selectors *toThis){
  Selectors *sel = toThis;
  Rules *currRule = sel->FirstRule;
  while(currRule!=NULL){
    currRule = currRule->Next;
  }
  currRule->Next = rule;
  return sel;
}
//OLD code to be cleaned and reused if possible.
int IsRuleBoundary(char ch){
  int i =0;
  for(i=0; i<RuleBoundaryCount; i++){
    if(ch==rule_boundaries[i])
      return 1; //success. rule boundary
  }
  return 0; //failure. not rule boundary
}

Rules* ruleizer(char *file_name){
  FILE *fp = fopen(file_name, "r");
  int space_seen =0;
  int opened_brace=0;
  char ch;
  Rules *start, *temp = (Rules*)malloc(sizeof(Rules)), *current;
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
          temp = (Rules *)malloc(sizeof(Rules));
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

void rule_printer(Rules *start){
  Rules *current = start;
  while(current->next!=NULL){
    printf("\n%s",current->rule_name);
    current = current->next;
  }
}