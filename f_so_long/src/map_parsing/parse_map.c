/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:02:01 by afocant           #+#    #+#             */
/*   Updated: 2024/09/28 16:21:58 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fn_get_window_dimensions(t_game *game, char *map_file)
{
	int		fd;
	int		nl;
	char	*line;

	fd = open(map_file, O_RDONLY);
	line = ft_get_next_line(fd);
	if (!line)
		fn_error_exit("Error parsing map", EINVAL, 2);
	nl = 1;
	game->columns = ft_strlen(line) - nl;
	game->rows = 0;
	while (line)
	{
		game->rows += 1;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
}

void	fn_pass_map_into_struct(t_game *game, char *map_file)
{
	int				fd;
	char			*line;
	unsigned int	i;

	fd = open(map_file, O_RDONLY);
	line = ft_get_next_line(fd);
	if (!line)
		fn_error_exit(NULL, errno, 3);
	game->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		fn_error_exit(NULL, ENOMEM, 4);
	i = 0;
	while (line)
	{
		game->map[i++] = line;
		line = ft_get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

void	fn_extract_game_info(t_game *game)
{
	unsigned int	row;
	unsigned int	col;

	game->collectibles = 0;
	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->columns)
		{
			if (game->map[row][col] == COLLECT)
				game->collectibles++;
			else if (game->map[row][col] == PLAYER)
			{
				game->y_player_pos = row;
				game->x_player_pos = col;
			}
			col++;
		}
		row++;
	}
}

void	fn_parse_map(t_game *game, char *map_file)
{
	fn_get_window_dimensions(game, map_file);
	fn_pass_map_into_struct(game, map_file);
	fn_extract_game_info(game);
}
