/* ************************************************************************** */
/*                                                                            */
/*   5_redirs.c                                           :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:16:55 by afocant           #+#    #+#             */
/*   Updated: 2025/03/28 19:22:35 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "expander.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void	redir_infile(char *filename, t_io *io, t_shell *shell)
{
	int	fd;

	if (access(filename, F_OK) != EXIT_SUCCESS)
		shell->flags |= ENOENT_FILE;
	else if (access(filename, R_OK) != EXIT_SUCCESS)
		shell->flags |= EACCES_FILE;
	fd = NO_FILE;
	fd = open(filename, O_RDONLY);
	if (fd == NO_FILE)
		return ;
	if (io->input != STDIN_FILENO)
		close (io->input);
	io->input = fd;
}

static void	redir_outfile(char *filename, int mode, t_io *io, t_shell *sh)
{
	int	fd;

	if (access(filename, F_OK) == EXIT_SUCCESS)
	{
		if (access(filename, W_OK) != EXIT_SUCCESS)
		{
			sh->flags |= EACCES_FILE;
			return ;
		}
	}
	fd = NO_FILE;
	if (mode == OUT)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	else if (mode == APPEND)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (fd == NO_FILE)
	{
		sh->flags |= ENOENT_FILE;
		return ;
	}
	if (io->output != STDOUT_FILENO)
		close (io->output);
	io->output = fd;
}

static char	*expand_redir(char **filename, t_shell *shell)
{
	if (has_expansion(*filename))
	{
		if (ft_strchr(*filename, '~'))
			tilde_expansion(filename, shell);
		if (ft_strchr(*filename, '$'))
			parameter_expansion(filename, shell);
		filename_expansion(filename, shell);
	}
	quote_removal(filename, shell);
	return (*filename);
}

void	visit_redir(t_redir *redir, t_io *io, t_shell *shell)
{
	if (redir->next)
		visit_node(redir->next, io, shell);
	if (shell->flags & EACCES_FILE || shell->flags & ENOENT_FILE)
		return ;
	expand_redir(&(redir->filename), shell);
	if (redir->type == IN)
		redir_infile(redir->filename, io, shell);
	else if (redir->type == OUT)
		redir_outfile(redir->filename, OUT, io, shell);
	else if (redir->type == APPEND)
		redir_outfile(redir->filename, APPEND, io, shell);
	check_redir_errors(redir->filename, shell);
}
