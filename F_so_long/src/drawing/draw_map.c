/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:02:18 by afocant           #+#    #+#             */
/*   Updated: 2024/08/27 14:02:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fn_draw_tile(t_game *game, void *sprite, unsigned int x, unsigned int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		sprite, x * TILE_WIDTH, y * TILE_HEIGHT);
}

int	fn_draw_map(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == WALL)
				fn_draw_tile(game, game->sprite.wall, x, y);
			else if (game->map[y][x] == EXIT)
				fn_draw_tile(game, game->sprite.exit, x, y);
			else if (game->map[y][x] == COLLECT)
				fn_draw_tile(game, game->sprite.object, x, y);
			else if (game->map[y][x] == EMPTY)
				fn_draw_tile(game, game->sprite.empty_tile, x, y);
			else if (game->map[y][x] == PLAYER)
				fn_draw_tile(game, game->sprite.player, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
