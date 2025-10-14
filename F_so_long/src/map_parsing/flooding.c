/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:02:09 by afocant           #+#    #+#             */
/*   Updated: 2024/09/24 12:01:25 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fn_flood_map(t_game *game, unsigned int y, unsigned int x)
{
	game->map[y][x] = 'F';
	if (game->map[y - 1][x] != WALL && game->map[y - 1][x] != 'F')
		fn_flood_map(game, y - 1, x);
	if (game->map[y][x - 1] != WALL && game->map[y][x - 1] != 'F')
		fn_flood_map(game, y, x - 1);
	if (game->map[y + 1][x] != WALL && game->map[y + 1][x] != 'F')
		fn_flood_map(game, y + 1, x);
	if (game->map[y][x + 1] != WALL && game->map[y][x + 1] != 'F')
		fn_flood_map(game, y, x + 1);
}

int	fn_check_flood_map(t_game *game)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->columns)
		{
			if (ft_strchr("EC", game->map[row][col]))
				return (FALSE);
			col++;
		}
		row++;
	}
	return (TRUE);
}

void	fn_copy_map(t_game *copy, t_game *game)
{
	unsigned int	i;

	copy->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!copy->map)
		fn_free_and_exit("Malloc on map copy has failed", errno, 185, game);
	i = 0;
	while (i < game->rows)
	{
		copy->map[i] = ft_strdup(game->map[i]);
		i++;
	}
	copy->map[i] = NULL;
	copy->rows = game->rows;
	copy->columns = game->columns;
}

void	fn_start_flooding(t_game *game)
{
	t_game			game_copy;

	fn_copy_map(&game_copy, game);
	fn_flood_map(&game_copy, game->y_player_pos, game->x_player_pos);
	if (!fn_check_flood_map(&game_copy))
		fn_free_and_exit("No winning path available", ENOENT, 75, game);
	fn_free_map(&game_copy);
}
