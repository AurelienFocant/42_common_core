#ifndef PROTOTYPES_LEXER_H
# define PROTOTYPES_LEXER_H

#include "lexer.h"

/*----------------  src/utils  ---------------*/
/* File: list_utils.c */
t_token	*last_token(t_token *lst);
void	add_back(t_token **token_list, t_token *new_token);
void	print_linked_list(t_token *token_list);


/*----------------  src  ---------------*/
/* File: token_utils.c */
char	peek(char *current);
int	advance(char **current);
void	print_token_class(t_token *token);

/* File: char_types.c */
int	is_operator(char c);
int	is_metacharacter(char c);
int	is_whitespace(char c);
int	is_eol(char *current);

/* File: tokenise_operators.c */
int	is_single_operator(char c);
t_token	*tokenise_single_operator(char **current);
int	is_double_operator(char c);
t_token *tokenise_double_operator(char **current);

/* File: tokenise_words.c */
int	is_word(char c);
char	*extract_lexeme(char *start, char *end);
t_token	*tokenise_word(char **current);

/* File: main.c */
t_token	*build_token(t_tk_class class, char *lexeme);
t_token	*lexer(char *input);

#endif
