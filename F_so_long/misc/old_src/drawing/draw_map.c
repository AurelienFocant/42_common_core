#include "so_long.h"

void	ft_retrieve_sprites(t_data *data)
{
	int	img_width;
	int	img_height;

	data->sprite.wall = mlx_xpm_file_to_image(data->mlx, "misc/sprites/rock.xpm", &img_width, &img_height);
	data->sprite.player = mlx_xpm_file_to_image(data->mlx, "misc/sprites/link_down.xpm", &img_width, &img_height);
	data->sprite.exit = mlx_xpm_file_to_image(data->mlx, "misc/sprites/exit.xpm", &img_width, &img_height);
	data->sprite.collectible = mlx_xpm_file_to_image(data->mlx, "misc/sprites/heart.xpm", &img_width, &img_height);
	data->sprite.empty_tile = mlx_xpm_file_to_image(data->mlx, "misc/sprites/bg.xpm", &img_width, &img_height);
}

void	ft_draw_tile(void *sprite, int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, sprite, x * TILE_WIDTH, y * TILE_HEIGHT);
}

int	ft_draw_map(t_data *data)
{
	unsigned int	row;
	unsigned int	column;

	mlx_clear_window(data->mlx, data->win);
	row = 0;
	while (row < data->y_axis_map_size)
	{
		column = 0;
		while (column < data->x_axis_map_size)
		{
			if (data->map[row][column] == WALL)
				ft_draw_tile(data->sprite.wall, column, row, data);
			else if (data->map[row][column] == EXIT)
				ft_draw_tile(data->sprite.exit, column, row, data);
			else if (data->map[row][column] == COLLECT)
				ft_draw_tile(data->sprite.collectible, column, row, data);
			else if (data->map[row][column] == EMPTY)
				ft_draw_tile(data->sprite.empty_tile, column, row, data);
			else if (data->map[row][column] == PLAYER)
				ft_draw_tile(data->sprite.player, column, row, data);
			column++;
		}
		row++;	
	}
	return (0);
}
