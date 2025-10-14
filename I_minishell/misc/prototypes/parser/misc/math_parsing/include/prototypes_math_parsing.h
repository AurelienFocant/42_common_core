#ifndef PROTOTYPES_MATH_PARSING_H
# define PROTOTYPES_MATH_PARSING_H

#include "math_parsing.h"

/*----------------  src  ---------------*/
/* File: lexer.c */
size_t	ft_toklen(char *s, char *e);
char	*ft_tokenise(char *s, char *e);
bool	ft_add_back(t_token **tokens, t_token *node);
bool	build_int_node(t_token **tokens, char *s, char *e);
bool	build_op_node(t_token **tokens, char *s, char *e);
t_token	*lexer(char *input);

/* File: main.c */

/* File: math_parsing.c */
void	consume(t_token **token);
char	next_token(t_token *token);
tree_node	*buildAddition(tree_node *left, tree_node *right);
tree_node	*buildNumber(t_token *token);
tree_node	*parseF(t_token **token);
tree_node	*buildMultiplication(tree_node *left, tree_node *right);
tree_node	*parseT(t_token **token);
tree_node	*parseE(t_token **token);

#endif
