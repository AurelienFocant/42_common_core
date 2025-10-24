/* ************************************************************************** */
/*                                                                            */
/*   0_check_count.c                                      :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/28 19:53:17 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "prototypes_miniRT.h"

int	check_object(char *line, int fd)
{
	if (object_kind(line) == SPHERE)
		return (check_sp(line, fd));
	if (object_kind(line) == PLANE)
		return (check_pl(line, fd));
	if (object_kind(line) == CYLINDER)
		return (check_cy(line, fd));
	if (object_kind(line) == CONE)
		return (check_co(line, fd));
	if (object_kind(line) == CUBE)
		return (check_cu(line, fd));
	file_error_exit(line, fd);
	return (0);
}

void	check_line_by_line(t_world *w, int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		free(line);
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (first_word(line) == LIGHT)
			w->light_count += check_light(line, fd);
		else if (first_word(line) == AMBIENT)
			check_ambient(line, fd);
		else if (first_word(line) == CAMERA)
			check_camera(line, fd);
		else if (first_word(line) == OBJECT)
			w->obj_count += check_object(line, fd);
		else if (first_word(line) == COMMENT)
			continue ;
		else if (is_just_whitespace(line))
			continue ;
		else
			file_error_exit(line, fd);
	}
	free(line);
}

void	check_filename_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		error_exit("Wrong filename\n");
	if (ft_strcmp(filename + len - 3, ".rt") != 0)
		error_exit("Wrong filename\n");
}

void	check_file_and_count(char *filename, t_world *w)
{
	int		fd;

	check_filename_extension(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Error opening file\n");
	check_line_by_line(w, fd);
	close(fd);
	if (w->light_count == 0 || w->obj_count == 0)
		error_exit("Not enough objects in file\n");
}
