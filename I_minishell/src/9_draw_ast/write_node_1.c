/* ************************************************************************** */
/*                                                                            */
/*   write_node_1.c                                       :::      ::::::::   */
/*   write_node_1.c                                     :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:17:45 by afocant           #+#    #+#             */
/*   Updated: 2025/02/05 19:29:02 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"
#include "lexer.h"
#include "parser.h"

#include <unistd.h>
#include <fcntl.h>

void	write_cmd_node(int fd, t_ast *ast, int *node_id, int my_id)
{
	if (ast->cmd.redir)
	{
		write_node_connection(fd, my_id, *node_id);
		write_node(fd, ast->cmd.redir, node_id);
	}
}

void	write_pipe_node(int fd, t_ast *ast, int *node_id, int my_id)
{
	if (ast->pipe.left)
	{
		write_node_connection(fd, my_id, *node_id);
		write_node(fd, ast->pipe.left, node_id);
	}
	if (ast->pipe.right)
	{
		write_node_connection(fd, my_id, *node_id);
		write_node(fd, ast->pipe.right, node_id);
	}
}

void	write_cond_node(int fd, t_ast *ast, int *node_id, int my_id)
{
	if (ast->cond.left)
	{
		write_node_connection(fd, my_id, *node_id);
		write_node(fd, ast->cond.left, node_id);
	}
	if (ast->cond.right)
	{
		write_node_connection(fd, my_id, *node_id);
		write_node(fd, ast->cond.right, node_id);
	}
}

void	write_redir_node(int fd, t_ast *ast, int *node_id, int my_id)
{
	if (ast->redir.next)
	{
		write_node_connection(fd, my_id, *node_id);
		write_node(fd, ast->redir.next, node_id);
	}
}
