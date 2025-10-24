#include "so_long.h"

void	ft_free_map(t_data *data)
{
	unsigned int	row;

	row = 0;
	while (row < data->y_axis_map_size)
		free(data->map[row++]);
	free(data->map);
}

int	ft_close_win(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		ft_free_map(data);
		exit(0);
	}
	if (key == ARROW_UP || key == KEY_W)
		ft_move_up(data);
	return (0);
}

int	ft_key_hook(int key, t_data *data)
{
	if (key == ARROW_UP || key == KEY_W)
		ft_move_up(data);
	/*
	if (key == ARROW_LEFT || key == KEY_A)
		ft_move_left(data);
	if (key == ARROW_DOWN || key == KEY_S)
		ft_move_down(data);
	if (key == ARROW_RIGHT || key == KEY_D)
		ft_move_right(data);
	*/
	return (0);
}

void	ft_minilibx_loop(t_data *data)
{
	mlx_hook(data->win, KEYDOWN, 0, ft_close_win, data);
	//mlx_key_hook(data->win, ft_key_hook, data);
	mlx_loop_hook(data->mlx, ft_draw_map, data);
	mlx_loop(data->mlx);
}
