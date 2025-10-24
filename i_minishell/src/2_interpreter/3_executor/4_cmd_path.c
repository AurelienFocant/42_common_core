/* ************************************************************************** */
/*                                                                            */
/*   4_cmd_path.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:26:07 by afocant           #+#    #+#             */
/*   Updated: 2025/03/19 20:51:57 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>
#include <errno.h>

static char	*cat_path_cmd(char *path, char *cmd)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (ft_strlen(path) + 1 + ft_strlen(cmd) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*path)
		res[i++] = *path++;
	res[i++] = '/';
	while (*cmd)
		res[i++] = *cmd++;
	res[i] = '\0';
	return (res);
}

static char	*search_in_path(char **path, char *cmd, t_shell *shell)
{
	char	**tmp;
	char	*exec_name;

	tmp = path;
	while (*path)
	{
		exec_name = cat_path_cmd(*path, cmd);
		if (!exec_name)
			return (exec_error(cmd, shell));
		if (access(exec_name, F_OK) == EXIT_SUCCESS)
		{
			if (access(exec_name, X_OK) == EXIT_SUCCESS)
			{
				ft_free_strv(tmp);
				return (exec_name);
			}
			if (errno == EACCES)
				shell->flags |= EACCES_CMD;
		}
		free(exec_name);
		path++;
	}
	ft_free_strv(tmp);
	return (NULL);
}

char	*search_path(char *cmd, t_shell *shell)
{
	char	*paths;
	char	**path;
	char	*exec_name;

	paths = find_env_var_value("PATH", shell);
	if (!paths)
		return (exec_error(cmd, shell));
	path = ft_split(paths, ':');
	if (!path)
		return (exec_error(cmd, shell));
	exec_name = search_in_path(path, cmd, shell);
	if (!exec_name)
		return (exec_error(cmd, shell));
	return (exec_name);
}
