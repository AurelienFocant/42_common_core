#include "picoshell.h"
#include "parser.h"
#include "lexer.h"
#include "interpreter.h"

t_token	*build_token(t_tk_class class, char *lexeme)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->class = class;
	token->lexeme = lexeme;
	token->next = NULL;
	return (token);
}

t_token	*lexer(char *input)
{
	t_token	*token_list;
	t_token	*token;
	char	*current;

	token_list = NULL;
	current = input;
	while (*current)
	{
		while (*current && is_whitespace(*current))
			current++;
		if (!*current)
			break;
		if (is_single_operator(*current))
			token = tokenise_single_operator(&current);
		else if (is_double_operator(*current))
			token = tokenise_double_operator(&current);
		else if (is_word(*current))
			token = tokenise_word(&current);
		else
		{
			printf("wrong char\n");
			exit(EXIT_FAILURE);
		}
		add_back(&token_list, token);
		current++;
	}
	// print_linked_list(tokens);
	return (token_list);
}
