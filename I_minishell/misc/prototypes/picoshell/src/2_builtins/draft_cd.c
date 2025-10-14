/*
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
	t_exit_code	status;

	status = EXIT_SUCCESS;
	old_pwd = get_current_dir(shell);
	if (!old_pwd)
		return (EXIT_FAILURE);
	target_dir = get_target_directory(cmd, shell, &status);
	if (!target_dir)
	{
		free(old_pwd);
		return (status);
	}
	status = change_directory(cmd, target_dir, old_pwd, shell);
	free(old_pwd);
	return (status);
}






void	update_env_var(char *name, char *value, t_shell *shell)
{
	t_strlst	*env;
	char		*new_var;
	t_strlst	*new_node;

	env = find_env_var(name, shell);
	new_var = ft_cat_strs(3, name, "=", value);
	if (!new_var)
		free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
	if (env)
	{
		free(env->str);
		env->str = new_var;
	}
	else
	{
		new_node = build_strlst(new_var);
		if (!new_node)
			free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
		strlstadd_back(&shell->envp, new_node);
		free(new_var);
	}
}

void	update_pwd_variables(char *old_pwd, t_shell *shell)
{
	char	*new_pwd;

	new_pwd = get_current_dir(shell);
	if (!new_pwd)
		return ;
	update_env_var("PWD", new_pwd, shell);
	update_env_var("OLDPWD", old_pwd, shell);
	free(new_pwd);
}

char	*handle_home_dir(t_exit_code *status, t_shell *shell)
{
	char	*target_dir;

	target_dir = find_env_var_value("HOME", shell);
	if (!target_dir || !*target_dir)
	{
		ft_dprintf(STDERR_FILENO, "tiny: cd: HOME not set\n");
		*status = EXIT_FAILURE;
		return (NULL);
	}
	return (target_dir);
}

char	*handle_oldpwd(t_exit_code *status, t_shell *shell)
{
	char	*target_dir;

	target_dir = find_env_var_value("OLDPWD", shell);
	if (!target_dir || !*target_dir)
	{
		ft_dprintf(STDERR_FILENO, "tiny: cd: OLDPWD not set\n");
		*status = EXIT_FAILURE;
		return (NULL);
	}
	return (target_dir);
}

*/
