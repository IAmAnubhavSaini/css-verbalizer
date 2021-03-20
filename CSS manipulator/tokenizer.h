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

#ifndef TOKENIZERH
#define TOKENIZERH

/* Data definition
 * Maximum css token size: like [1px 1px 1px black, 2px -2px 2px yello...]
 */
#define MaxCssTokenSize 100

/* Data Structure
 * t_node contains a character array or string.
 * and a next pointer. 
 */
typedef struct token_node t_node;
struct token_node {
    char token_name[MaxCssTokenSize];
    t_node *next;
};


/* Dynamic Is input char a Token Boundary function
 * Dynamic: checks into external dependency of valid_css_token_boundaries
 * IsTokenBoundary: what constitutes a token boundary
 * input: character to be tested
 * output: 1-success, 0-failure. due to "Is"
 */
int DYN_IsTokenBoundary(char);

/* tokenizer function 
 * input: file path of the css file
 * output: first token of the linked-list of the tokens
 */
t_node *tokenizer(char *);

/* token printer prints tokens line wise it encountered, one per line
 * input: first token node
 * output: on standard output, no return
 */
void token_printer(t_node *);

#include "token_DS.c"
#include "tokenizer.c"

#endif
