#include "so_long.h"

void	ft_get_window_dimensions(t_data *data)
{
	int		fd;
	int		nl;
	char	*line;
	size_t	rows;
	size_t	columns;

	fd = ft_open_map(data->map_file);
	line = ft_get_next_line(fd);
	if (!line)
		ft_error_exit("invalid map");
	nl = 1;
	rows = 0;
	while (line)
	{
		columns = 0;
		while (line[columns])
			columns++;
		data->x_axis_map_size = columns - nl;
		if (ft_strlen(line) - nl != data->x_axis_map_size)
			ft_error_exit("invalid map");
		rows++;
		free(line);
		line = ft_get_next_line(fd);
	}
	data->y_axis_map_size = rows;
	close(fd);
}

void	ft_get_player_position(t_data *data)
{
	unsigned int	row;
	unsigned int	column;

	row = 0;
	while (row < data->y_axis_map_size)
	{
		column = 0;
		while (column < data->x_axis_map_size)
		{
			if (data->map[row][column] == PLAYER)
			{
				data->y_player_pos = row;
				data->x_player_pos = column;
			}
			column++;
		}
		row++;
	}
}

void	ft_parse_map(t_data *data)
{ 
	int				fd;
	unsigned int	row;
	char			*line;

	fd = ft_open_map(data->map_file);
	data->map = malloc(sizeof(char *) * (data->y_axis_map_size));
	line = ft_get_next_line(fd);
	if (!line)
		ft_error_exit("invalid map");
	row = 0;
	while (line)
	{
		data->map[row] = line;
		line = ft_get_next_line(fd);
		row++;
	}
	ft_get_player_position(data);
	ft_retrieve_sprites(data);
	close(fd);
}
// don't forget to free the map !!
