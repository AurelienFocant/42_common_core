#include "so_long.h"

/*----------------  draw_map.c  ---------------*/
void	ft_retrieve_sprites(t_data *data);
void	ft_draw_tile(void *sprite, int x, int y, t_data *data);
int	ft_draw_map(t_data *data);

/*----------------  moving.c  ---------------*/
void	ft_move_up(t_data *data);

/*----------------  errors.c  ---------------*/
void	ft_error_exit(char *msg);

/*----------------  main.c  ---------------*/
void	ft_check_args(int argc);
int	main(int argc, char **argv);

/*----------------  map_checking.c  ---------------*/
int	ft_check_file_extension(char *map_file);
int	ft_open_map(char *map_file);
void	ft_check_for_valid_map(char *map_file, t_data *data);

/*----------------  map_parsing.c  ---------------*/
void	ft_get_window_dimensions(t_data *data);
void	ft_get_player_position(t_data *data);
void	ft_parse_map(t_data *data);

/*----------------  minilibx_loop.c  ---------------*/
void	ft_free_map(t_data *data);
int	ft_close_win(int key, t_data *data);
int	ft_key_hook(int key, t_data *data);
void	ft_minilibx_loop(t_data *data);

/*----------------  mlx_init.c  ---------------*/
void	ft_mlx_init(t_data *data);
