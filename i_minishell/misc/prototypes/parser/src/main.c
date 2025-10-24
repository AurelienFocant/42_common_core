#include "parser.h"

typedef enum
{
	WORD = 100, TK_PIPE, GREAT, LESS, DGREAT, DLESS,
	LEFT_PAREN, RIGHT_PAREN, LOG_AND, LOG_OR,
	AMPERSAND, SEMICOLON
}	t_tk_class;

typedef struct s_token
{
	t_tk_class		class;
	char			*lexeme;
	struct s_token	*next;
}	t_token;

bool	consume(t_token **token)
{
	if ((*token)->next == NULL)
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

t_node	*parse_cmd(t_token **token)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->type = CMD;
	node->content.cmd.string = ft_strdup((*token)->lexeme);
	node->content.cmd.next = NULL;
	return (node);
}

t_node	*build_binary_node(t_node *left, t_node *right, int operator)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	// protect malloc
	node->type = operator;
	node->content.binary.left = left;
	node->content.binary.right = right;
	return (node);
}

t_node	*parse_pipeline(t_token **token)
{
	t_node	*left;
	t_node	*right;
	t_node	*node;

	left = parse_cmd(token);
	if (match(token, TK_PIPE))
	{
		consume(token);
		right = parse_pipeline(token);
		node = build_binary_node(left, right, TK_PIPE);
		return (node);
	}
	return (left);
}

t_node	*parser(t_token **tokens)
{
	t_node	*ast;

	ast = parse_pipeline(tokens);
	return (ast);
}

int	main()
{
	t_node	*ast;
	t_token	*tokens;
	t_token	tk1;
	t_token	tk2;
	t_token	tk3;

	tokens = &tk1;
	tk1.class = WORD;
	tk1.lexeme = ft_strdup("echo hello");
	tk1.next = &tk2;

	tk2.class = TK_PIPE;
	tk2.lexeme = NULL;
	tk2.next = &tk3;

	tk3.class = WORD;
	tk3.lexeme = ft_strdup("cat -e");
	tk3.next = NULL;

	ast = parser(&tokens);
	(void) ast;

	return 0;
}
