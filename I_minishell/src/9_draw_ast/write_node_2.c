/* ************************************************************************** */
/*                                                                            */
/*   write_node_2.c                                       :::      ::::::::   */
/*   write_node_2.c                                     :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:17:45 by afocant           #+#    #+#             */
/*   Updated: 2025/02/05 19:28:19 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"
#include "lexer.h"
#include "parser.h"

#include <unistd.h>
#include <fcntl.h>

void	write_heredoc_node(int fd, t_ast *ast, int *node_id, int my_id)
{
	if (ast->heredoc.next)
	{
		write_node_connection(fd, my_id, *node_id);
		write_node(fd, ast->heredoc.next, node_id);
	}
}

void	write_subsh_node(int fd, t_ast *ast, int *node_id, int my_id)
{
	if (ast->subsh.next)
	{
		write_node_connection(fd, my_id, *node_id);
		write_node(fd, ast->subsh.next, node_id);
	}
}
