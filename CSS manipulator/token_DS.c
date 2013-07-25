#ifndef CSSVERBALIZERTOKENDS
#define CSSVERBALIZERTOKENDS

#include "../anubhavDS-C/helpers.c"

//Maximum css token size: like [1px 1px 1px black, 2px -2px 2px yello...]
#define MaxCssTokenSize 100

char valid_css_token_boundaries []= {' ', ',', ';', ':', '}', '{', '\n', '\t', '(', ')', '#'};
#define TokenBoundaryCount 11
#define ISTOKENBOUNDARY(c)	\
(\
c == valid_css_token_boundaries[0]  ||  \
c == valid_css_token_boundaries[1]  ||  \
c == valid_css_token_boundaries[2]  ||  \
c == valid_css_token_boundaries[3]  ||  \
c == valid_css_token_boundaries[4]  ||  \
c == valid_css_token_boundaries[5]  ||  \
c == valid_css_token_boundaries[6]  ||  \
c == valid_css_token_boundaries[7]  ||  \
c == valid_css_token_boundaries[8]  ||  \
c == valid_css_token_boundaries[9]  ||  \
c == valid_css_token_boundaries[10]     \
)
char valid_css_chars_extra [] = { '@', '!', '-', '#', '.', '>', '+',  };
#define ISCSSCHAR(c) \
(\
ISALPHA(c) 						||	\
c == valid_css_chars_extra [0]	||	\
c == valid_css_chars_extra [1]	||	\
c == valid_css_chars_extra [2]	||	\
c == valid_css_chars_extra [3]		\
)

struct token_node {
  char token_name[MaxCssTokenSize];
  struct token_node *next;
};
typedef struct token_node t_node;

//Dynamic: when code-plugging is available
int DYN_IsTokenBoundary(char ch){
  int i =0;
  for(i=0; i<TokenBoundaryCount; i++){
    if(ch==valid_css_token_boundaries[i])
      return 1; //success. token boundary
  }
  return 0; //failure. not token boundary
}

#endif