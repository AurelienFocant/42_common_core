/* ************************************************************************** */
/*                                                                            */
/*   mlx_init.c                                           :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	multiple_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	printf("%x\n", color);
	i = 0;
	while (i < MAX)
	{
		j = 0;
		while (j < MAX)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

t_color	get_pixel(t_texture *tex, int x, int y)
{
	int				offset;
	unsigned char	*pixel;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (color(0, 0, 0));
	offset = (y * tex->size_line + x * (tex->bpp / 8));
	pixel = (unsigned char *)(tex->addr + offset);
	return (color((float) pixel[2] / 255.0f,
			(float) pixel[1] / 255.0f, (float) pixel[0] / 255.0f));
}

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)(data->addr + offset) = color;
	}
	else
		ft_dprintf(2, "pixel out of bound\n");
}
