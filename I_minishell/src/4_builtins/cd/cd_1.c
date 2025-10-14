/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:24:46 by afocant           #+#    #+#             */
/*   Updated: 2025/03/31 11:37:05 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

char	*get_current_dir(t_shell *shell)
{
	char	*current_dir;

	(void)shell;
	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		ft_dprintf(STDERR_FILENO,
			"tiny: cd: error retrieving current directory\n");
		return (NULL);
	}
	return (current_dir);
}

char	*get_target_directory(t_cmd cmd, t_shell *shell, t_exit_code *status)
{
	if (cmd.name[1] && cmd.name[2] && ft_strcmp(cmd.name[1], "--")
		!= EXIT_SUCCESS)
	{
		ft_dprintf(STDERR_FILENO, "tiny: cd: too many arguments\n");
		*status = EXIT_FAILURE;
		return (NULL);
	}
	else if (cmd.name[1] && ft_strcmp(cmd.name[1], "--") == EXIT_SUCCESS
		&& !cmd.name[2])
		return (handle_home_dir(status, shell));
	else if (cmd.name[1] && ft_strcmp(cmd.name[1], "--") == EXIT_SUCCESS
		&& cmd.name[2])
		return (cmd.name[2]);
	else if (!cmd.name[1])
		return (handle_home_dir(status, shell));
	else if (ft_strcmp(cmd.name[1], "-") == EXIT_SUCCESS)
		return (handle_oldpwd(status, shell));
	else
		return (cmd.name[1]);
}

void	print_chdir_error(char *target_dir)
{
	if (errno == ENOENT)
		ft_dprintf(STDERR_FILENO,
			"tiny: cd: %s: No such file or directory\n", target_dir);
	else if (errno == EACCES)
		ft_dprintf(STDERR_FILENO,
			"tiny: cd: %s: Permission denied\n", target_dir);
	else if (errno == ENOTDIR)
		ft_dprintf(STDERR_FILENO,
			"tiny: cd: %s: Not a directory\n", target_dir);
	else
		ft_dprintf(STDERR_FILENO,
			"tiny: cd: %s: Error changing directory\n", target_dir);
}

t_exit_code	change_directory(t_cmd cmd,
		char *target_dir, char *old_pwd, t_shell *shell)
{
	char	*new_dir;

	if (chdir(target_dir) != 0)
	{
		print_chdir_error(target_dir);
		return (EXIT_FAILURE);
	}
	if (cmd.name[1] && ft_strcmp(cmd.name[1], "-") == EXIT_SUCCESS)
	{
		new_dir = getcwd(NULL, 0);
		if (new_dir)
		{
			ft_putendl_fd(new_dir, STDOUT_FILENO);
			free(new_dir);
		}
	}
	update_pwd_variables(old_pwd, shell);
	return (EXIT_SUCCESS);
}

t_exit_code	cd_builtin(t_cmd cmd, t_shell *shell)
{
	char		*old_pwd;
	char		*target_dir;
	char		*temp_old_pwd;
	t_exit_code	status;

	target_dir = NULL;
	status = EXIT_SUCCESS;
	old_pwd = find_env_var_value("PWD", shell);
	if (!old_pwd || !*old_pwd)
	{
		old_pwd = get_current_dir(shell);
		if (!old_pwd)
			return (EXIT_FAILURE);
		temp_old_pwd = old_pwd;
		status = change_directory(cmd, target_dir, old_pwd, shell);
		free(temp_old_pwd);
		return (status);
	}
	target_dir = get_target_directory(cmd, shell, &status);
	if (!target_dir)
		return (status);
	status = change_directory(cmd, target_dir, old_pwd, shell);
	return (status);
}
