/* ************************************************************************** */
/*                                                                            */
/*   cube_mapping1.c                                      :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_pair	cube_uv_up(t_point p)
{
	t_pair	pair;

	pair.u = fmodf(1 - p.x, 2.) / 2;
	pair.v = fmodf(1 - p.z, 2.) / 2;
	return (pair);
}

t_pair	cube_uv_down(t_point p)
{
	t_pair	pair;

	pair.u = fmodf(1 - p.x, 2.) / 2;
	pair.v = fmodf(p.z + 1, 2.) / 2;
	return (pair);
}

t_pair	cube_map(t_point p, int face)
{
	if (face == FRONT)
		return (cube_uv_front(p));
	if (face == BACK)
		return (cube_uv_back(p));
	if (face == LEFT)
		return (cube_uv_left(p));
	if (face == RIGHT)
		return (cube_uv_right(p));
	if (face == UP)
		return (cube_uv_up(p));
	return (cube_uv_down(p));
}
