/* ************************************************************************** */
/*                                                                            */
/*   9_exec_errors.c                                      :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:39:45 by afocant           #+#    #+#             */
/*   Updated: 2025/03/24 14:03:17 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

void	check_path_errors(char *cmd, t_shell *shell)
{
	if (shell->flags & ISDIR_CMD)
	{
		print_file_error("tiny", cmd, ": Is a directory\n", shell);
		free_shell(shell);
		exit(EACCES_ERROR);
	}
	if (shell->flags & EACCES_CMD)
	{
		print_file_error("tiny: ", cmd, ": Permission denied\n", shell);
		free_shell(shell);
		exit(EACCES_ERROR);
	}
	if (shell->flags & ENOENT_CMD)
	{
		if (ft_strchr(cmd, '/'))
			print_file_error("tiny",
				cmd, ": No such file or directory\n", shell);
		else
			print_file_error("tiny",
				cmd, ": command not found\n", shell);
		free_shell(shell);
		exit(ENOENT_ERROR);
	}
}

char	*exec_error(char *cmd, t_shell *shell)
{
	shell->flags |= ENOENT_CMD;
	shell->flags |= EXEC_PANIC;
	return (cmd);
}
