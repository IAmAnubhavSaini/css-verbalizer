#define TokenBoundaryCount 8
#define MaxTokenSize 100
//char token_boundaries []= {' ', ',', ';', ':', '}', '{', '\n', '\t' };
char token_boundaries []= {';', ':', '}', '{', '\n', '\t'};

struct token_node {
  char token_name[MaxTokenSize];
  struct token_node *next;
};
typedef struct token_node t_node;
int IsTokenBoundary(char ch){
  int i =0;
  for(i=0; i<TokenBoundaryCount; i++){
    if(ch==token_boundaries[i])
      return 1; //success. token boundary
  }
  return 0; //failure. not token boundary
}
