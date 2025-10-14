/* ************************************************************************** */
/*                                                                            */
/*   0_parse_world.c                                      :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	parse_obj(char *line)
{
	if (object_kind(line) == SPHERE)
		return (parse_sp(line));
	if (object_kind(line) == PLANE)
		return (parse_pl(line));
	if (object_kind(line) == CYLINDER)
		return (parse_cy(line));
	if (object_kind(line) == CONE)
		return (parse_co(line));
	if (object_kind(line) == CUBE)
		return (parse_cu(line));
	return (parse_pl(NULL));
}

void	fill_world(int fd, t_world *w)
{
	int			i;
	int			j;
	char		*line;

	i = 0;
	j = 0;
	line = NULL;
	while (1)
	{
		free(line);
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (first_word(line) == LIGHT)
			w->lights[i++] = parse_light(line);
		else if (first_word(line) == AMBIENT)
			w->ambient = parse_ambient(line);
		else if (first_word(line) == CAMERA)
			w->camera = parse_camera(line);
		else if (first_word(line) == OBJECT)
			w->obj[j++] = parse_obj(line);
	}
	free(line);
}

void	parse_world(char *filename, t_world *w)
{
	int			fd;

	w->obj = malloc(sizeof(t_object) * w->obj_count);
	if (!w->obj)
		error_exit("Malloc error\n");
	w->lights = malloc(sizeof(t_light) * w->light_count);
	if (!w->obj)
	{
		free(w->obj);
		error_exit("Malloc error\n");
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(w->obj);
		free(w->lights);
		error_exit("Error opening file\n");
	}
	fill_world(fd, w);
	close(fd);
}
