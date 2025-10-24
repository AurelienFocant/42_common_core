/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:06:26 by afocant           #+#    #+#             */
/*   Updated: 2024/08/29 19:12:56 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long.h"
# include "libft.h"
# include "mlx.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>

# define HOR_RESOLUTION 2560
# define VER_RESOLUTION 1440
# define TILE_WIDTH 64
# define TILE_HEIGHT 64

# define WALL		'1'
# define PLAYER		'P'
# define EXIT		'E'
# define COLLECT	'C'
# define EMPTY		'0'

# define NO_MASK	 0
# define KEYDOWN	 2
# define RED_LIGHT	17

# define ESC	53
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define ARROW_UP		126 
# define ARROW_LEFT		123 
# define ARROW_DOWN		125 
# define ARROW_RIGHT	124 
# define UP		0 
# define LEFT	1 
# define DOWN	2 
# define RIGHT	3

# define FALSE 0
# define TRUE 1
# define ENDGAME 2

typedef struct s_sprite
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*object;
	void	*empty_tile;
}				t_sprite;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	size_t			rows;
	size_t			columns;
	unsigned int	y_player_pos;
	unsigned int	x_player_pos;
	unsigned int	collectibles;
	t_sprite		sprite;
}				t_game;

/*----------------  check_args.c  ---------------*/
void			fn_check_map_file(char *map_file);
void			fn_check_nb_args(int argc);
void			fn_check_args(int argc, char **argv);

/*----------------  error_utils.c  ---------------*/
void			fn_error_exit(char *msg, int errnum, int exitcode);
void			fn_free_null(char *ptr);
void			fn_free_map(t_game *game);
void			fn_free_and_exit(char *msg,
					int errnum, int exitcode, t_game *game);
int				fn_is_sprite_null(t_sprite sprite);

/*----------------  draw_map.c  ---------------*/
void			fn_draw_tile(t_game *game,
					void *sprite, unsigned int x, unsigned int y);
int				fn_draw_map(t_game *game);

/*----------------  main.c  ---------------*/
void			fn_init_struct(t_game *game);

/*----------------  flooding.c  ---------------*/
void			fn_flood_map(t_game *game, unsigned int y, unsigned int x);
int				fn_check_flood_map(t_game *game);
void			fn_copy_map(t_game *copy, t_game *game);
void			fn_start_flooding(t_game *game);

/*----------------  map_errors.c  ---------------*/
void			fn_check_map_size(t_game *game);
void			fn_check_if_rectangle(t_game *game);
void			fn_check_four_walls(t_game *game);
void			fn_check_elements(t_game *game);
void			fn_check_map_for_errors(t_game *game);

/*----------------  parse_map.c  ---------------*/
void			fn_get_window_dimensions(t_game *game, char *map_file);
void			fn_pass_map_into_struct(t_game *game, char *map_file);
void			fn_extract_game_info(t_game *game);
void			fn_parse_map(t_game *game, char *map_file);

/*----------------  loop_mlx.c  ---------------*/
int				fn_exit_game(t_game *game);
int				fn_key_hook(int key, t_game *game);
void			fn_loop_mlx(t_game *game);

/*----------------  setup_mlx.c  ---------------*/
void			fn_retrieve_sprites(t_game *game);
void			fn_setup_mlx(t_game *game);

/*----------------  moving.c  ---------------*/
unsigned int	fn_find_new_y(t_game *game, int direction);
unsigned int	fn_find_new_x(t_game *game, int direction);
void			fn_assign_sprite(t_game *game, int direction);
int				fn_move(t_game *game, int direction);

#endif
