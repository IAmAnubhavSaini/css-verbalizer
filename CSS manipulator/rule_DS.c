#define RuleBoundaryCount 2
#define MaxRuleSize 100

char rule_boundaries []= {';','\n'};

struct rule_node {
  char rule_name[MaxRuleSize];
  struct rule_node *next;
};
typedef struct rule_node t_node;
int IsRuleBoundary(char ch){
  int i =0;
  for(i=0; i<RuleBoundaryCount; i++){
    if(ch==rule_boundaries[i])
      return 1; //success. rule boundary
  }
  return 0; //failure. not rule boundary
}