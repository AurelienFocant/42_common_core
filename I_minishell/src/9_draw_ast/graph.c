/* ************************************************************************** */
/*                                                                            */
/*   graph.c                                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:17:45 by afocant           #+#    #+#             */
/*   Updated: 2025/03/20 12:06:32 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"
#include "lexer.h"
#include "parser.h"
#include "libft.h"

#include <unistd.h>
#include <fcntl.h>

void	write_node_connection(int fd, int parent_id, int child_id)
{
	ft_dprintf(fd, "\tnode%d -> node%d;\n", parent_id, child_id);
}

void	write_node(int fd, t_ast *ast, int *node_id)
{
	int	my_id;

	if (!ast)
		return ;
	my_id = *node_id;
	write_label(fd, ast, my_id);
	(*node_id)++;
	if (ast->type == CMD)
		write_cmd_node(fd, ast, node_id, my_id);
	else if (ast->type == PIPE)
		write_pipe_node(fd, ast, node_id, my_id);
	else if (ast->type == COND)
		write_cond_node(fd, ast, node_id, my_id);
	else if (ast->type == REDIR)
		write_redir_node(fd, ast, node_id, my_id);
	else if (ast->type == HEREDOC)
		write_heredoc_node(fd, ast, node_id, my_id);
	else if (ast->type == SUBSHELL)
		write_subsh_node(fd, ast, node_id, my_id);
}

bool	visualizer(t_ast*ast)
{
	int	fd;
	int	node_id;

	fd = open("./misc/graph/tree.dot", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("fd -1 could not open tree.dot\n");
		return (true);
	}
	node_id = 0;
	ft_dprintf(fd, "digraph Minishell_AST {\n");
	write_node(fd, ast, &node_id);
	ft_dprintf(fd, "}\n");
	close(fd);
	return (false);
}
