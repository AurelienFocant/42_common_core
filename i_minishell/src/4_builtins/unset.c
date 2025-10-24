/* ************************************************************************** */
/*                                                                            */
/*   unset.c                                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:17:57 by afocant           #+#    #+#             */
/*   Updated: 2025/03/20 11:53:08 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>

static t_exit_code	unset_free_first_node(t_shell *shell)
{
	t_strlst	*tmp;

	tmp = shell->envp;
	shell->envp = shell->envp->next;
	free(tmp->str);
	free(tmp);
	return (EXIT_SUCCESS);
}

static t_exit_code	unset_free_node(t_strlst *envp)
{
	t_strlst	*tmp;

	tmp = envp->next;
	envp->next = envp->next->next;
	free(tmp->str);
	free(tmp);
	return (EXIT_SUCCESS);
}

t_exit_code	unset_builtin(t_cmd cmd, t_shell *shell)
{
	t_strlst	*envp;
	int			i;

	envp = shell->envp;
	i = 1;
	while (cmd.name[i])
	{
		if (ft_strncmp(envp->str, cmd.name[i], ft_strlen(cmd.name[i]))
			== EXIT_SUCCESS)
			return (unset_free_first_node(shell));
		while (envp->next)
		{
			if (ft_strncmp(envp->next->str, cmd.name[i], ft_strlen(cmd.name[i]))
				== EXIT_SUCCESS)
				if (*(envp->next->str + ft_strlen(cmd.name[i])) == '=')
					return (unset_free_node(envp));
			envp = envp->next;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
