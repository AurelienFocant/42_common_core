#include "so_long.h"

int	ft_check_file_extension(char *map_file)
{
	char	*ptr;

	ptr = ft_strchr(map_file, '.');
	if (!ptr)
		ft_error_exit("map is not of ber type");
	if (ft_strncmp(++ptr, "ber", 4) != 0)
		ft_error_exit("map is not of ber type");
	return (1);
}

int	ft_open_map(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error_exit("couldn't open map");
	return (fd);
}

void	ft_check_for_valid_map(char *map_file, t_data *data)
{
	ft_check_file_extension(map_file);
	data->map_file = map_file;
	//ft_check_map();
	//ft_backtrack_map();
	ft_get_window_dimensions(data);
}
