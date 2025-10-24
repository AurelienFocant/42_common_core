/* ************************************************************************** */
/*                                                                            */
/*   mlx_hook.c                                           :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/20 18:33:47 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	out_prog(t_mlx *interface)
{
	if (interface->data->img)
		mlx_destroy_image(interface->mlx, interface->data->img);
	if (interface->win)
	{
		mlx_clear_window(interface->mlx, interface->win);
		mlx_destroy_window(interface->mlx, interface->win);
	}
	if (interface->mlx)
	{
//		mlx_destroy_display(interface->mlx);
		free(interface->mlx);
	}
	exit(0);
	return (0);
}

static int	key_event(int keycode, t_mlx *interface)
{
	if (keycode == 65307 || keycode == 53)
		out_prog(interface);
	return (0);
}

void	events_init(t_mlx *interface)
{
	mlx_hook(interface->win, 2, 1L << 0, &key_event, interface);
	mlx_hook(interface->win, 17, 0, &out_prog, interface);
}
