/* ************************************************************************** */
/*                                                                            */
/*   parse_options.c                                      :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:33:06 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:24:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <stdlib.h>

static void	parse_option_letters(char *arg, t_shell *shell)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'c')
			shell->flags |= COMMAND_MODE;
		else if (arg[i] == 'd')
			shell->flags |= DEBUG_FLAG;
		else if (arg[i] == 'a')
			shell->flags |= GRAPH_FLAG;
		else if (arg[i] == 'g')
			shell->flags |= GRAPH_FLAG;
		else
		{
			ft_dprintf(STDERR_FILENO,
				"tinyshell: -%c: invalid option\n", arg[i]);
			free_shell(shell);
			exit(INVALID_OPTION);
		}
		i++;
	}
}

static void	parse_option_names(char *arg, t_shell *shell)
{
	if (ft_strcmp(arg + 2, "command") == EXIT_SUCCESS)
		shell->flags |= COMMAND_MODE;
	else if (ft_strcmp(arg + 2, "debug") == EXIT_SUCCESS)
		shell->flags |= DEBUG_FLAG;
	else if (ft_strcmp(arg + 2, "ast") == EXIT_SUCCESS)
		shell->flags |= GRAPH_FLAG;
	else if (ft_strcmp(arg + 2, "graph") == EXIT_SUCCESS)
		shell->flags |= GRAPH_FLAG;
	else
	{
		ft_dprintf(STDERR_FILENO, "tinyshell: %s: invalid option\n", arg);
		free_shell(shell);
		exit(INVALID_OPTION);
	}
}

static void	parse_options(char **args, t_shell *shell)
{
	int	dashes;

	while (*args)
	{
		if ((*args)[0] == '-')
		{
			dashes = count_dashes(*args);
			if (dashes == 1)
				parse_option_letters(*args, shell);
			else if (dashes == 2)
				parse_option_names(*args, shell);
			else
			{
				ft_dprintf(STDERR_FILENO,
					"tinyshell: %s: invalid option\n", *args);
				free_shell(shell);
				exit(INVALID_OPTION);
			}
		}
		args++;
	}
}

void	parse_args(int argc, char **argv, t_shell *shell)
{
	char	*file;

	(void) argc;
	parse_options(argv + 1, shell);
	file = get_first_non_option(argv + 1);
	if (shell->flags & COMMAND_MODE)
	{
		if (file)
			shell->input = file;
		else
			free_and_exit_shell("tiny: -c: option requires an argument",
				INVALID_OPTION, shell);
	}
	else if (file)
	{
		shell->flags |= SCRIPT_MODE;
		shell->script_file = file;
	}
	else
		shell->flags |= INTERACT_MODE;
}
