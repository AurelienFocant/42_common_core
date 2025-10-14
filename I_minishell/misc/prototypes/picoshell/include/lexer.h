#ifndef LEXER_H
# define LEXER_H

/*
 * TOKEN_CLASSES
 *
 * WORD
 * PIPE
 * GREAT
 * LESS
 * DGREAT
 * DLESS
 *
 * LEFT_PAREN
 * RIGHT_PAREN
 * LOG_AND
 * LOG_OR
 *
 * AMPERSAND
 * SEMICOLON
 *
 */

/*
 * metacharacters : 
 * ' ', '\t', '\n'
 * ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, ‘>’
 */

#define FALSE 0
#define TRUE 1

typedef enum
{
	WORD = 100, TK_PIPE, GREAT, LESS, DGREAT, DLESS,
	LEFT_PAREN, RIGHT_PAREN, D_AND, D_OR,
	AMPERSAND, SEMICOLON
}	t_tk_class;

typedef struct s_token
{
	t_tk_class		class;
	char			*lexeme;
	struct s_token	*next;
}	t_token;

#endif
