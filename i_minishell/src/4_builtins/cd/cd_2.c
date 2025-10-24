/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:12:38 by slangero          #+#    #+#             */
/*   Updated: 2025/03/31 11:46:55 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

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
	char	*env_pwd;

	update_env_var("OLDPWD", old_pwd, shell);
	new_pwd = NULL;
	if (handle_current_wd(&new_pwd, shell) == EXIT_FAILURE)
	{
		env_pwd = find_env_var_value("PWD", shell);
		if (env_pwd && *env_pwd)
			update_env_var("PWD", env_pwd, shell);
		return ;
	}
	update_env_var("PWD", new_pwd, shell);
	free(new_pwd);
}
