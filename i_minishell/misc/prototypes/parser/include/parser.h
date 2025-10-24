#ifndef PARSER_H
# define PARSER_H

// NODE_TYPES
//
//  type binary	---> pipe, and_if, or_if
//
//  type cmd
//
//  type redir	---> <, <<, >, >>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft.h"

typedef enum
{
	PIPE, AND_IF, OR_IF
}	t_op_type;

typedef enum
{
	IN, OUT, HEREDOC, APPEND
}	t_redir_type;

typedef enum
{
	BINARY, CMD, REDIR
}	t_nodetype;

typedef struct s_binary
{
	t_op_type		op_type;
	struct s_node	*left;
	struct s_node	*right;
}	t_binary;

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

typedef union
{
	t_binary	binary;
	t_cmd		cmd;
	t_redir		redir;
}	u_nodecontent;

typedef struct s_node
{
	t_nodetype		type;
	u_nodecontent	content;
}	t_node;

#endif
