#include "so_long.h"

void	ft_move_up(t_data *data)
{
	int y;
	int x;

	y = data->y_player_pos;
	x = data->x_player_pos;
	data->map[y][x] = EMPTY;
	if (data->map[y-1][x] != WALL)
	{
		if (data->map[y-1][x] == EMPTY)
		{
			data->map[y][x] = EMPTY;
			data->map[y-1][x] = PLAYER;
		}
		data->y_player_pos -= 1;
	}
}
