/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:53:03 by slangero          #+#    #+#             */
/*   Updated: 2025/03/15 12:39:25 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"
#include "libft.h"

#include <unistd.h>
#include <fcntl.h>

void	print_heredoc_label(int fd, t_ast *ast, int my_id)
{
	ft_dprintf(fd,
		"\tnode%d [label=\"HEREDOC\\n%s\"];\n", my_id, ast->heredoc.delim);
}

void	write_label(int fd, t_ast *ast, int my_id)
{
	if (!ast)
		ft_dprintf(fd, "\tnode%d [label=\"NULL\"];\n", my_id);
	if (ast->type == CMD)
		print_cmd_label(fd, ast, my_id);
	if (ast->type == PIPE)
		ft_dprintf(fd, "\tnode%d [label=\"PIPE\"];\n", my_id);
	if (ast->type == COND)
		print_cond_label(fd, ast, my_id);
	if (ast->type == REDIR)
		print_redir_label(fd, ast, my_id);
	if (ast->type == HEREDOC)
		print_heredoc_label(fd, ast, my_id);
	if (ast->type == SUBSHELL)
		ft_dprintf(fd, "\tnode%d [label=\"SUBSH\"];\n", my_id);
}
