/* ************************************************************************** */
/*                                                                            */
/*   export_concat.c                                      :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:06:11 by afocant           #+#    #+#             */
/*   Updated: 2025/03/20 11:50:00 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

static void	concat_env_var(t_strlst *node, char *new_value, t_shell *shell)
{
	size_t	l1;
	size_t	l2;
	char	*new;
	size_t	i;

	l1 = ft_strlen(node->str);
	l2 = ft_strlen(new_value);
	new = malloc((l1 + l2 + 1) * sizeof(char));
	if (!new)
		free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
	i = 0;
	while (l1--)
	{
		new[i] = node->str[i];
		i++;
	}
	while (l2--)
		new[i++] = *new_value++;
	new[i] = '\0';
	free(node->str);
	node->str = new;
}

static char	*copy_assigned_value(char *s)
{
	char	*res;
	size_t	i;

	res = malloc((ft_strlen(s) - 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (*s != '+')
		res[i++] = *s++;
	s++;
	while (*s)
		res[i++] = *s++;
	res[i] = '\0';
	return (res);
}

void	cat_env_var(char *assign, t_shell *shell)
{
	char		*var_name;
	t_strlst	*env_var;
	t_strlst	*new;

	var_name = extract_env_var_name(assign, ft_strchr(assign, '+'), shell);
	env_var = find_env_var(var_name, shell);
	free(var_name);
	if (!env_var)
	{
		new = malloc(sizeof(t_strlst));
		if (!new)
			free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
		new->next = NULL;
		new->str = copy_assigned_value(assign);
		if (!new->str)
		{
			free(new);
			free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
		}
		strlstadd_back(&shell->envp, new);
	}
	else
		concat_env_var(env_var, ft_strchr(assign, '=') + 1, shell);
}
