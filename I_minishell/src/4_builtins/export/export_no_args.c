/* ************************************************************************** */
/*                                                                            */
/*   export_no_args.c                                     :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:52:00 by afocant           #+#    #+#             */
/*   Updated: 2025/03/25 17:40:39 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>

static char	*copy_env_with_quotes(char *str)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(str) + 3);
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str == '=')
		{
			res[i++] = *str++;
			break ;
		}
		res[i++] = *str++;
	}
	res[i++] = '"';
	while (*str)
		res[i++] = *str++;
	res[i++] = '"';
	res[i] = '\0';
	return (res);
}

static t_strlst	*copy_envp(t_strlst *envp, t_shell *shell)
{
	t_strlst	*lst;
	t_strlst	*new;

	lst = NULL;
	while (envp)
	{
		new = malloc(sizeof(t_strlst));
		if (!new)
		{
			free_strlst(&lst);
			free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
		}
		new->next = NULL;
		new->str = copy_env_with_quotes(envp->str);
		if (!new->str)
		{
			free_strlst(&lst);
			free(new);
			free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
		}
		strlstadd_back(&lst, new);
		envp = envp->next;
	}
	return (lst);
}

static void	swap_nodes_data(t_strlst *n1, t_strlst *n2)
{
	char	*tmp;

	tmp = n1->str;
	n1->str = n2->str;
	n2->str = tmp;
}

static void	sort_envp(t_strlst *env)
{
	t_strlst	*tmp;

	while (env)
	{
		tmp = env;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (ft_strcmp(env->str, tmp->str) > 0)
				swap_nodes_data(env, tmp);
		}
		env = env->next;
	}
}

void	export_no_arg(t_shell *shell)
{
	t_strlst	*env;

	env = copy_envp(shell->envp, shell);
	sort_envp(env);
	while (env)
	{
		ft_dprintf(STDOUT_FILENO, "declare -x ");
		ft_dprintf(STDOUT_FILENO, "%s\n", env->str);
		env = env->next;
	}
	free_strlst(&env);
}
