/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:04:54 by afocant           #+#    #+#             */
/*   Updated: 2024/05/07 22:51:09 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
	{
		printf("args !");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (2);
	line = "";
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
