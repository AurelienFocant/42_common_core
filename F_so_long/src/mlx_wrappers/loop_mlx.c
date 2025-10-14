/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:01:56 by afocant           #+#    #+#             */
/*   Updated: 2024/08/29 17:56:57 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fn_exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	fn_free_map(game);
	exit(0);
}

int	fn_key_hook(int key, t_game *game)
{
	int	direction;

	direction = -1;
	if (key == ESC)
		fn_exit_game(game);
	if (key == ARROW_UP || key == KEY_W)
		direction = UP;
	else if (key == ARROW_LEFT || key == KEY_A)
		direction = LEFT;
	else if (key == ARROW_DOWN || key == KEY_S)
		direction = DOWN;
	else if (key == ARROW_RIGHT || key == KEY_D)
		direction = RIGHT;
	if (direction >= UP && direction <= RIGHT)
	{
		fn_assign_sprite(game, direction);
		fn_move(game, direction);
	}
	return (TRUE);
}

void	fn_loop_mlx(t_game *game)
{
	mlx_hook(game->win, KEYDOWN, NO_MASK, fn_key_hook, game);
	mlx_hook(game->win, RED_LIGHT, NO_MASK, fn_exit_game, game);
	mlx_loop_hook(game->mlx, fn_draw_map, game);
	mlx_loop(game->mlx);
}
