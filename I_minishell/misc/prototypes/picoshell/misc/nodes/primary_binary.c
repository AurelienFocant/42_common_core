typedef enum e_dir
{
	CMD,
	IN,
	OUT,
	HEREDOC,
	APPEND
}	t_ptype;

typedef struct
{
	t_ptype	type;
	char	*string;	
	t_node	*next;
}	t_primary;

typedef enum e_op
{
	PIPE,
	AND_IF,
	OR_IF
}	t_op;

typedef struct s_binary
{
	t_op	op;
	t_node	*left;
	t_node	*right;
}	t_binary;

typedef union
{
	t_binary	binary;
	u_primary	primary;
}	u_nodedata;

typedef enum e_nodetype
{
	BINARY,
	PRIMARY
}	t_nodetype;

typedef struct s_node
{
	t_nodetype	type;
	u_nodedata	data;
}	t_node;

// ========================================= //

node->data.binary.op;
node->data.binary.left;
node->data.binary.right;

node->data.primary.type;
node->data.primary.string;
node->data.primary.next;

// ========================================= //

if (node->type == PRIMARY)
{
	if (node->data.primary.type == CMD)
	{
		while (node->data.primary.next)
		{
			dupfiles(node->data.primary.type, node->data.primary.string)
			node = node->data.primary.next;
		}
	}
}

if (node->type == BINARY)
{
	if (node->data.binary.op == PIPE)
	{
		pipe(pipefd);
		lh.ctxt.out = pipe[STDOUT_FILENO];
		lh.ctxt.close = pipe[STDIN_FILENO];
		parse_pipeline(node->data.binary.left, lh.ctxt);
		rh.ctxt.out = pipe[STDOUT_FILENO];
		rh.ctxt.close = pipe[STDIN_FILENO];
		parse_pipeline(node->data.binary.right, rh.ctxt);
	}
	if (node->data.binary.op == AND_IF)
	{
		if (parse_pipeline(node->data.binary.left) == EXIT_SUCCESS)
			parse_pipeline(node->data.binary.right);
	}
}
