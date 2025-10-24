/* ************************************************************************** */
/*                                                                            */
/*   export.c                                             :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:00:51 by afocant           #+#    #+#             */
/*   Updated: 2025/03/25 17:46:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>

void	update_existing_env_var(t_strlst *var, char *new_var, t_shell *sh)
{
	free(var->str);
	var->str = ft_strdup(new_var);
	if (!var->str)
		free_and_exit_shell("malloc failed", EXIT_FAILURE, sh);
}

static void	create_new_env_var(char *new_var, t_shell *shell)
{
	t_strlst	*new;

	new = malloc(sizeof(t_strlst));
	if (!new)
		free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
	new->next = NULL;
	new->str = ft_strdup(new_var);
	if (!new->str)
	{
		free(new);
		free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
	}
	strlstadd_back(&shell->envp, new);
}

static void	export_var(char *new_var, t_shell *shell)
{
	t_strlst	*var;
	char		*var_name;

	var_name = extract_env_var_name(new_var, ft_strchr(new_var, '='), shell);
	var = find_env_var(var_name, shell);
	free(var_name);
	if (!var)
		create_new_env_var(new_var, shell);
	else
		update_existing_env_var(var, new_var, shell);
}

t_exit_code	export_builtin(t_cmd cmd, t_shell *shell)
{
	int		i;
	char	*assign;
	bool	error;

	error = false;
	if (!cmd.name[1])
		export_no_arg(shell);
	i = 1;
	while (cmd.name[i])
	{
		if (!is_identifier(cmd.name[i], &i, &error))
			continue ;
		assign = has_assignment(cmd.name[i], &i);
		if (!assign)
			continue ;
		if (assign && *(assign - 1) == '+')
			cat_env_var(cmd.name[i], shell);
		else
			export_var(cmd.name[i], shell);
		i++;
	}
	if (error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
