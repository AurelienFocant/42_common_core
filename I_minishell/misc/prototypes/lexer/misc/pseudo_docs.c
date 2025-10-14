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

typedef enum
{
	WORD, PIPE, GREAT, LESS, DREAT, DLESS,
	LEFT_PAREN, RIGHT_PAREN, LOG_AND, LOG_OR,
	AMPERSAND, SEMICOLON
}	t_tk_class;

typedef struct s_token
{
	t_tk_class	class,
	char		*lexeme,
	t_token		*next,
}	t_token;

/*
 * metacharacters : 
 * ' ', '\t', '\n'
 * ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, ‘>’
 */




c == '('
token '('


c == '<'
if ++c -- '<'
	token HEREDOC
else
	token REDIR


while (! is_metachar())
	c++;



char *input = cat -e >file;

cat -e >infile
|  |  
s  c			


if (is_char())
{
	while (! is_metachar())
		c++;
	create_word_token(start, current);
	add_back(tk_list);
}


