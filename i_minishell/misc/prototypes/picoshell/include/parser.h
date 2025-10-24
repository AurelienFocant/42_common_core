#ifndef PARSER_H
# define PARSER_H

// NODE_TYPES
//
//  type binary	---> pipe, and_if, or_if
//
//  type cmd
//
//  type redir	---> <, <<, >, >>

#include <stdbool.h>

typedef enum e_nodetype
{
	PIPE = 10, COND, CMD, REDIR
}	t_nodetype;

typedef enum e_condtype
{
	AND = 20, IF
}	t_condtype;

typedef enum e_redir_type
{
	IN = 30, OUT, HEREDOC, APPEND
}	t_redir_type;

typedef struct s_cond
{
	t_condtype		cond;
	struct s_node	*left;
	struct s_node	*right;
}	t_cond;

typedef struct s_pipe
{
	struct s_node	*left;
	struct s_node	*right;
}	t_pipe;

typedef struct s_cmd
{
	char			*string;
	struct s_node	*next;
}	t_cmd;

typedef struct s_redir
{
	t_redir_type	type;
	char			*filename;
	struct s_node	*next;
}	t_redir;

typedef struct s_hdoc
{
	char			*delim;
	char			**document;
	struct s_node	*next;
}	t_hdoc;

typedef union
{
	t_cond	cond;
	t_pipe	pipe;
	t_cmd	cmd;
	t_redir	redir;
	t_hdoc	heredoc;
}	u_nodedata;

typedef struct s_node
{
	t_nodetype	type;
	u_nodedata	data;
}	t_node;

#endif
