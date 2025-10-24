#include "picoshell.h"

bool	write_to_hist_file(char *line, t_shell *shell)
{
	char	*home;
	char	*hist_file;
	int		fd;

	home = expand("HOME=", shell);		// CAREFUL with HOMEBREW being used for HOME, '=' !
	hist_file = ft_strjoin(home, "/.tiny_history");
	if (!hist_file)
		return (false);
	fd = open(hist_file, O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (fd == NO_FILE)
		ft_putendl_fd("couldnt open history file", STDERR_FILENO);
	ft_putendl_fd(line, fd);
	free(hist_file);
	close(fd);
	return (true);
}

bool	populate_history(char *line, t_shell *shell)
{
	add_history(line);
	write_to_hist_file(line, shell);
	return (true);
}

void	read_history_file(t_shell *shell)
{
	char	*home;
	char	*hist_file;
	int		fd;
	char	*line;

	home = expand("HOME=", shell);
	hist_file = ft_strjoin(home, "/.tiny_history");
	if (access(hist_file, R_OK) == EXIT_SUCCESS)
	{
		fd = open(hist_file, O_RDONLY);
		line = ft_get_next_line(fd);
		line = ft_strtrim(line, "\n");
		while (line)
		{
			add_history(line);
			free(line);
			line = ft_get_next_line(fd);
			line = ft_strtrim(line, "\n");
		}
		close(fd);
	}
}
