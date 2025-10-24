/* ************************************************************************** */
/*                                                                            */
/*   pwd.c                                                :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:24:46 by afocant           #+#    #+#             */
/*   Updated: 2025/03/10 16:13:57 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>
#include <stdlib.h>

t_exit_code	pwd_builtin(t_shell *shell)
{
	char	*current_dir;

	(void)shell;
	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		ft_dprintf(STDERR_FILENO,
			"tiny: pwd: error retrieving current directory\n");
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(current_dir, STDOUT_FILENO);
	free(current_dir);
	return (EXIT_SUCCESS);
}
