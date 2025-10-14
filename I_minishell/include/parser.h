/* ************************************************************************** */
/*                                                                            */
/*   parser.h                                             :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:28:51 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:40:38 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_condtype
{
	AND_IF, OR_IF
}	t_cond_type;

typedef enum e_redir_type
{
	IN, OUT, APPEND
}	t_redir_type;

typedef enum e_nodetype
{
	SUBSHELL, COND, PIPE, CMD, REDIR, HEREDOC
}	t_node_type;

typedef struct s_subsh
{
	struct s_ast	*next;
}	t_subsh;

typedef struct s_cond
{
	t_cond_type		type;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_cond;

typedef struct s_pipe
{
	struct s_ast	*left;
	struct s_ast	*right;
}	t_pipe;

typedef struct s_cmd
{
	char			**name;
	struct s_ast	*redir;
}	t_cmd;

typedef struct s_redir
{
	t_redir_type	type;
	char			*filename;
	struct s_ast	*next;
}	t_redir;

typedef struct s_hdoc
{
	char			*delim;
	int				document;
	struct s_ast	*next;
}	t_hdoc;

typedef struct s_ast
{
	t_node_type	type;
	union
	{
		t_subsh	subsh;
		t_cond	cond;
		t_pipe	pipe;
		t_cmd	cmd;
		t_redir	redir;
		t_hdoc	heredoc;
	};
}	t_ast;

#endif
