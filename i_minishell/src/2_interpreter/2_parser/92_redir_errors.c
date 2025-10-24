/* ************************************************************************** */
/*                                                                            */
/*   91_redir_errors.c                                    :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:02:31 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:23:28 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

char	*print_file_error(char *sh, char *filename, char *msg, t_shell *shell)
{
	char	*errmsg;
	size_t	len;
	char	*line_nb;

	errmsg = NULL;
	if (shell->flags & INTERACT_MODE)
		errmsg = ft_cat_strs(4, sh, ": ", filename, msg);
	else
	{
		line_nb = ft_itoa(shell->line_nb);
		if (shell->flags & SCRIPT_MODE)
			errmsg = ft_cat_strs(6, shell->script_file,
					": line ", line_nb, ": ", filename, msg);
		else
			errmsg = ft_cat_strs(6, sh,
					": line ", line_nb, ": ", filename, msg);
		free(line_nb);
	}
	if (!errmsg)
		return (syntax_malloc_failed(shell));
	len = ft_strlen(errmsg);
	write(STDERR_FILENO, errmsg, len);
	free(errmsg);
	return (msg);
}

void	check_redir_errors(char *filename, t_shell *shell)
{
	if (shell->flags & ENOENT_FILE)
	{
		print_file_error("tiny",
			filename, ": No such file or directory\n", shell);
		shell->exit_code = EXIT_FAILURE;
	}
	if (shell->flags & EACCES_FILE)
	{
		print_file_error("tiny",
			filename, ": Permission denied\n", shell);
		shell->exit_code = EXIT_FAILURE;
	}
}
