/* ************************************************************************** */
/*                                                                            */
/*   populate_history.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:31:37 by afocant           #+#    #+#             */
/*   Updated: 2025/03/20 11:55:02 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>
#include <fcntl.h>

#include <readline/history.h>

static char	*get_new_line(int fd)
{
	char	*tmp;
	char	*line;

	tmp = ft_get_next_line(fd);
	line = ft_strtrim(tmp, "\n");
	free(tmp);
	return (line);
}

static char	*construct_histfile(t_shell *shell)
{
	char	*home;
	char	*histfile;

	home = find_env_var_value("HOME", shell);
	if (!home)
		return (NULL);
	histfile = ft_strjoin(home, "/.tiny_history");
	if (!histfile)
		return (NULL);
	return (histfile);
}

bool	read_histfile(t_shell *shell)
{
	int		fd;
	char	*line;

	if (!shell->histfile)
		shell->histfile = construct_histfile(shell);
	fd = open(shell->histfile, O_RDONLY | O_CREAT, 0600);
	if (fd == NO_FILE)
	{
		ft_dprintf(STDERR_FILENO, "problem reading history\n");
		return (false);
	}
	line = get_new_line(fd);
	while (line)
	{
		add_history(line);
		free(line);
		line = get_new_line(fd);
	}
	close(fd);
	return (true);
}

bool	populate_histfile(char *line, char *histfile)
{
	int		fd;

	fd = open(histfile, O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (fd == NO_FILE || !histfile)
	{
		ft_dprintf(STDERR_FILENO, "problem writing to history\n");
		return (false);
	}
	ft_dprintf(fd, "%s\n", line);
	add_history(line);
	close(fd);
	return (true);
}
