#include "picoshell.h"
#include "parser.h"
#include "lexer.h"
#include "interpreter.h"

bool	consume(t_token **token)
{
	if ((*token) == NULL)
	{
		printf("end of tokens\n");
		return (false);
	}
	(*token) = (*token)->next;
	return (true);
}

bool	match(t_token **token, t_tk_class class)
{
	if ((*token)->next && (*token)->next->class == class)
	{
		consume(token);
		return (true);
	}
	return (false);
}

t_node	*parser(t_token **tokens)
{
	t_node	*ast;

	ast = parse_pipeline(tokens);
	return (ast);
}
