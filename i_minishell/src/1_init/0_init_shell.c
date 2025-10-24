/* ************************************************************************** */
/*                                                                            */
/*   init_shell.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:50:42 by afocant           #+#    #+#             */
/*   Updated: 2025/03/24 13:04:44 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>

static void	update_shlvl(t_shell *shell)
{
	t_strlst	*var;
	int			n;
	char		*nbr;
	char		*shlvl;

	var = find_env_var("SHLVL", shell);
	if (var)
	{
		n = ft_atoi(find_env_var_value("SHLVL", shell));
		nbr = ft_itoa(++n);
		if (!nbr)
			free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
		shlvl = ft_cat_strs(2, "SHLVL=", nbr);
		free(nbr);
		if (!shlvl)
			free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
		update_existing_env_var(var, shlvl, shell);
		free(shlvl);
	}
}

static t_strlst	*init_env(char **envp, t_shell *shell)
{
	t_strlst	*env;

	env = strv_to_strlst(envp);
	if (!env)
		return (NULL);
	shell->envp = env;
	update_shlvl(shell);
	return (env);
}

void	init_shell(char **envp, t_shell *shell)
{
	shell->std_in = dup(STDIN_FILENO);
	shell->std_out = dup(STDOUT_FILENO);
	shell->flags = 0;
	shell->histfile = NULL;
	shell->script_file = NULL;
	shell->line_nb = 1;
	shell->input = NULL;
	shell->token_stream = NULL;
	shell->ast_root = NULL;
	shell->last_child = 0;
	shell->nb_of_children = 0;
	shell->exit_code = EXIT_SUCCESS;
	shell->envp = init_env(envp, shell);
}
