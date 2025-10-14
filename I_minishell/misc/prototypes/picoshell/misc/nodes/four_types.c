typedef enum e_dir
{
	IN,
	OUT,
	HEREDOC,
	APPEND
}	t_dir;

typedef struct s_redir
{
	t_dir	dir;
	char	*filename;
	t_node	*next;
}	t_redir;

typedef struct s_cmd
{
	char	*string;
	t_node	*next;
}	t_cmd;

typedef enum e_op
{
	AND_IF,
	OR_IF
}	t_op;

typedef struct
{
	t_op	op;
	t_node	*left;
	t_node	*right;
}	t_cond;

typedef struct
{
	t_node	*left;
	t_node	*right;
}	t_pipe;

typedef union
{
	t_cond	cond;
	t_pipe	pipe;
	t_cmd	cmd;
	t_redir	redir;
}	u_nodedata;

typedef enum e_nodetype
{
	COND,
	PIPE,
	CMD,
	REDIR
}	t_nodetype;

typedef struct s_node
{
	t_nodetype	type;
	u_nodedata	data;
}	t_node;

// ========================================= //

node->data.cond.op;
node->data.cond.left;
node->data.cond.right;

node->data.pipe.left;
node->data.pipe.right;

node->data.cmd.string;
node->data.cmd.next;

node->data.redir.type;
node->data.redir.filename;
node->data.redir.next;
