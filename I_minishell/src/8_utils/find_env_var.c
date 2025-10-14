/* ************************************************************************** */
/*                                                                            */
/*   find_env_var.c                                       :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:19:38 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:24:07 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>

char	*extract_env_var_name(char *start, char *end, t_shell *shell)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = get_word_len(start, end);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		free_and_exit_shell("malloc failed", EXIT_FAILURE, shell);
	i = 0;
	while (start < end)
	{
		res[i++] = *start;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	*find_env_var_value(char *str, t_shell *shell)
{
	char		*env;
	t_strlst	*envp;
	size_t		len;

	len = ft_strlen(str);
	envp = shell->envp;
	while (envp)
	{
		env = envp->str;
		if (ft_strncmp(str, env, len) == EXIT_SUCCESS)
			if (*(env + len) == '=')
				return (env + len + 1);
		envp = envp->next;
	}
	return ("");
}

t_strlst	*find_env_var(char *str, t_shell *shell)
{
	char		*env;
	t_strlst	*envp;
	size_t		len;

	len = ft_strlen(str);
	envp = shell->envp;
	while (envp)
	{
		env = envp->str;
		if (ft_strncmp(str, env, len) == EXIT_SUCCESS)
			if (*(env + len) == '=')
				return (envp);
		envp = envp->next;
	}
	return (NULL);
}
