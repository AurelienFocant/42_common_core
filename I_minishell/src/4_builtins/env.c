/* ************************************************************************** */
/*                                                                            */
/*   env.c                                                :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:03 by afocant           #+#    #+#             */
/*   Updated: 2025/02/23 18:25:14 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>

t_exit_code	env_builtin(t_shell *shell)
{
	t_strlst	*env;

	env = shell->envp;
	while (env)
	{
		ft_putendl_fd(env->str, STDOUT_FILENO);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
