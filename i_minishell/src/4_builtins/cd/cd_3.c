/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:39:13 by slangero          #+#    #+#             */
/*   Updated: 2025/03/31 11:48:52 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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

int	handle_current_wd(char **pwd_str, t_shell *shell)
{
	char	*buf;
	char	*ret;

	buf = malloc(PATH_MAX);
	if (!buf)
		return (EXIT_FAILURE);
	ret = getcwd(buf, PATH_MAX);
	if (!ret)
		return (handle_getcwd_error(buf, pwd_str, shell));
	*pwd_str = buf;
	return (EXIT_SUCCESS);
}

int	handle_getcwd_error(char *buf, char **pwd_str, t_shell *shell)
{
	if (errno == ENOENT)
		return (handle_enoent_error(buf, pwd_str, shell));
	ft_dprintf(STDERR_FILENO, "tiny: getcwd: %s\n", strerror(errno));
	free(buf);
	return (EXIT_FAILURE);
}

int	handle_enoent_error(char *buf, char **pwd_str, t_shell *shell)
{
	char	*pwd;

	ft_dprintf(STDERR_FILENO,
		"tiny: cd: error retrieving current directory: "
		"getcwd: cannot access parent directories: %s\n",
		strerror(errno));
	pwd = find_env_var_value("PWD", shell);
	if (pwd && *pwd)
	{
		*pwd_str = ft_strdup(pwd);
		free(buf);
		return (EXIT_SUCCESS);
	}
	free(buf);
	return (EXIT_FAILURE);
}
