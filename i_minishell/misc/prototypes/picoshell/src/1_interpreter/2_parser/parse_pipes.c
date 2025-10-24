#include "picoshell.h"
#include "parser.h"
#include "lexer.h"
#include "interpreter.h"

t_node	*build_pipe_node(t_node *left, t_node *right)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	// protect malloc
	node->type = PIPE;
	node->data.pipe.left = left;
	node->data.pipe.right = right;
	return (node);
}

bool	is_tk_pipe(t_token **token)
{
	if (!(*token))
		return (false);
	if ((*token)->class == TK_PIPE)
		return (true);
	return (false);
}

t_node	*parse_pipeline(t_token **token)
{
	t_node	*node;
	t_node	*other_node;

	node = parse_simple_cmd(token);
	while (true)
	{
		if (is_tk_pipe(token))
		{
			consume(token);
			other_node = parse_simple_cmd(token);
			node = build_pipe_node(node, other_node);
		}
		else
			return (node);
	}
	return (NULL);
}
