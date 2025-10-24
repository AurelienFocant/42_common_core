/* ************************************************************************** */
/*                                                                            */
/*   free_ast2.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:44:19 by afocant           #+#    #+#             */
/*   Updated: 2025/03/15 14:02:31 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "parser.h"

#include <stdlib.h>

void	*free_cond(t_cond cond)
{
	free_node(cond.left);
	free_node(cond.right);
	return (NULL);
}

void	*free_pipe(t_pipe pipe)
{
	free_node(pipe.left);
	free_node(pipe.right);
	return (NULL);
}

void	*free_cmd(t_cmd cmd)
{
	ft_free_strv(cmd.name);
	if (cmd.redir)
		free_node(cmd.redir);
	return (NULL);
}

void	*free_redir(t_redir redir)
{
	if (redir.filename)
		free(redir.filename);
	redir.filename = NULL;
	if (redir.next)
		free_node(redir.next);
	return (NULL);
}

void	*free_heredoc(t_hdoc hdoc)
{
	free(hdoc.delim);
	close(hdoc.document);
	if (hdoc.next)
		free_node(hdoc.next);
	return (NULL);
}
