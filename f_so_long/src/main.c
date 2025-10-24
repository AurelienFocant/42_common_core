/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:03:08 by afocant           #+#    #+#             */
/*   Updated: 2024/08/27 14:03:09 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fn_init_struct(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->rows = 0;
	game->columns = 0;
	game->x_player_pos = 0;
	game->y_player_pos = 0;
	game->collectibles = 0;
	game->sprite.wall = NULL;
	game->sprite.player = NULL;
	game->sprite.exit = NULL;
	game->sprite.object = NULL;
	game->sprite.empty_tile = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	errno = 0;
	fn_init_struct(&game);
	fn_check_args(argc, argv);
	fn_parse_map(&game, argv[1]);
	fn_check_map_for_errors(&game);
	fn_setup_mlx(&game);
	fn_loop_mlx(&game);
}
