/* ************************************************************************** */
/*                                                                            */
/*   exit.c                                               :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:59:50 by afocant           #+#    #+#             */
/*   Updated: 2025/03/31 21:38:47 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>

static bool	is_numeric_arg(char *s)
{
	if (!s)
		return (true);
	if (!*s)
		return (false);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

static int	exit_count_args(char **args)
{
	int	n;

	n = 0;
	while (*args)
	{
		n++;
		args++;
	}
	return (n);
}

static int	exit_too_many_args(void)
{
	ft_dprintf(STDERR_FILENO, "exit\n");
	ft_dprintf(STDERR_FILENO, "tiny: exit: too many arguments\n");
	return (EXIT_FAILURE);
}

t_exit_code	exit_builtin(t_cmd cmd, t_shell *shell)
{
	int	n;

	if (!is_numeric_arg(cmd.name[1]))
	{
		if (shell->flags & INTERACT_MODE)
			ft_dprintf(STDERR_FILENO, "exit\n");
		ft_dprintf(STDERR_FILENO,
			"tiny: exit: %s: numeric argument required\n", cmd.name[1]);
		free_shell(shell);
		exit(2);
	}
	else if (exit_count_args(cmd.name + 1) > 1)
		return (exit_too_many_args());
	if (cmd.name[1])
	{
		n = ft_atoi(cmd.name[1]);
		if (n < 0)
			n = 256 + n;
	}
	else
		n = shell->exit_code;
	if (shell->flags & INTERACT_MODE)
		ft_dprintf(STDERR_FILENO, "exit\n");
	free_shell(shell);
	exit(n);
}
