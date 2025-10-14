/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:01:52 by afocant           #+#    #+#             */
/*   Updated: 2024/08/29 17:47:36 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Sprites are the work of thblonde@student.s19.be
 */
void	fn_retrieve_sprites(t_game *game)
{
	int	img_width;
	int	img_height;

	game->sprite.wall = mlx_xpm_file_to_image(game->mlx,
			"misc/sprites/rock.xpm", &img_width, &img_height);
	game->sprite.player = mlx_xpm_file_to_image(game->mlx,
			"misc/sprites/link_down.xpm", &img_width, &img_height);
	game->sprite.exit = mlx_xpm_file_to_image(game->mlx,
			"misc/sprites/exit.xpm", &img_width, &img_height);
	game->sprite.object = mlx_xpm_file_to_image(game->mlx,
			"misc/sprites/heart.xpm", &img_width, &img_height);
	game->sprite.empty_tile = mlx_xpm_file_to_image(game->mlx,
			"misc/sprites/bg.xpm", &img_width, &img_height);
	if (fn_is_sprite_null(game->sprite))
		fn_free_and_exit("Problem retrieving sprites", ENOENT, 5, game);
}

void	fn_setup_mlx(t_game *game)
{
	int	window_width;
	int	window_height;

	window_height = game->rows * TILE_WIDTH;
	window_width = game->columns * TILE_WIDTH;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		fn_free_map(game);
		fn_error_exit("mlx init failed", ENOENT, 6);
	}
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			"The Legend of Thomas, the Prequel");
	fn_retrieve_sprites(game);
}
