/* ************************************************************************** */
/*                                                                            */
/*   echo.c                                               :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:24:46 by afocant           #+#    #+#             */
/*   Updated: 2025/03/19 20:58:06 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>

static bool	is_invalid_option(char *options, char *str)
{
	if (count_dashes(str) != 1)
		return (true);
	str++;
	while (*str)
	{
		if (!ft_strchr(options, *str))
			return (true);
		str++;
	}
	return (false);
}

static void	write_echo_arg(t_cmd cmd, int i)
{
	ft_putstr_fd(cmd.name[i], STDOUT_FILENO);
	if (cmd.name[i + 1])
		write(STDOUT_FILENO, " ", 1);
}

t_exit_code	echo_builtin(t_cmd cmd)
{
	bool	endl;
	char	*arg;
	int		i;

	endl = true;
	if (cmd.name[1])
	{
		arg = get_first_non_option(cmd.name + 1);
		i = 1;
		while (cmd.name[i] != arg)
		{
			if (is_invalid_option("n", (cmd.name[i])))
				break ;
			endl = false;
			i++;
		}
		while (cmd.name[i])
			write_echo_arg(cmd, i++);
	}
	if (endl)
		write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}
