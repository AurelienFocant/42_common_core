/* ************************************************************************** */
/*                                                                            */
/*   error_exit.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	error_exit(char *s)
{
	size_t	res;

	res = 0;
	while (res != 6)
		res = write(STDERR_FILENO, "Error\n", 6);
	res = 0;
	while (res != ft_strlen(s))
		res = write(STDERR_FILENO, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}

void	file_error_exit(char *line, int fd)
{
	size_t	res;

	res = 0;
	while (res != 6)
		res = write(STDERR_FILENO, "Error\n", 6);
	res = 0;
	while (res != 25)
		res = write(STDERR_FILENO,
				"Error in world file at: \n", 25);
	res = 0;
	while (res != ft_strlen(line))
		res = write(STDERR_FILENO, line, ft_strlen(line));
	free(line);
	close(fd);
	exit(EXIT_FAILURE);
}

void	failed_texture_msg(t_object *o)
{
	o->material.pattern.type = EMPTY;
	ft_dprintf(STDERR_FILENO, "Wrong texture file\n");
}
