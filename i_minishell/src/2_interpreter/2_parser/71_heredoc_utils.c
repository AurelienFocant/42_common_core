/* ************************************************************************** */
/*                                                                            */
/*   71_heredoc2.c                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:19:30 by afocant           #+#    #+#             */
/*   Updated: 2025/03/31 13:54:46 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <signal.h>

extern int	g_signum;

char	has_quote(char *s)
{
	while (*s)
	{
		if (*s == '\'')
			return ('\'');
		else if (*s == '"')
			return ('"');
		s++;
	}
	return (0);
}

int	hdoc_interrupted(int *pipev, char *line, t_shell *shell)
{
	close(pipev[STDIN_FILENO]);
	close(pipev[STDOUT_FILENO]);
	free(line);
	shell->flags |= HEREDOC_SIGINT;
	shell->exit_code = 128 + SIGINT;
	g_signum = 0;
	return (NO_FILE);
}

int	hdoc_unexp_eof(char	*delim)
{
	ft_dprintf(STDERR_FILENO,
		"tiny: warning: here-document delimited by EOF (wanted `%s')\n",
		delim);
	return (EXIT_SUCCESS);
}

int	hdoc_pipe_error(t_shell *shell)
{
	ft_dprintf(STDERR_FILENO, "pipe syscall failed\n");
	shell->flags |= HEREDOC_SIGINT;
	return (NO_FILE);
}
