#include "so_long.h"

void	ft_mlx_init(t_data *data)
{
	int	window_width;
	int	window_height;

	window_width = data->x_axis_map_size * TILE_WIDTH;
	window_height = data->y_axis_map_size * TILE_WIDTH;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		//free map
		ft_error_exit("mlx init failed");
	}
	data->win = mlx_new_window(data->mlx, window_width, window_height, "plouf");
	data->img = mlx_new_image(data->mlx, window_width, window_height);
	mlx_get_data_addr(data->img, &(data->bits_per_pixel), \
			&(data->bytes_per_line), &(data->endian));
}
