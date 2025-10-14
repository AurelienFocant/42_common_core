/* ************************************************************************** */
/*                                                                            */
/*   cube_mapping2.c                                      :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_pair	cube_uv_front(t_point p)
{
	t_pair	pair;

	pair.u = fmodf(p.x + 1, 2.) / 2;
	pair.v = fmodf(p.y + 1, 2.) / 2;
	return (pair);
}

t_pair	cube_uv_back(t_point p)
{
	t_pair	pair;

	pair.u = fmodf(1 - p.x, 2.) / 2;
	pair.v = fmodf(p.y + 1, 2.) / 2;
	return (pair);
}

t_pair	cube_uv_left(t_point p)
{
	t_pair	pair;

	pair.u = fmodf(p.z + 1, 2.) / 2;
	pair.v = fmodf(p.y + 1, 2.) / 2;
	return (pair);
}

t_pair	cube_uv_right(t_point p)
{
	t_pair	pair;

	pair.u = fmodf(1 - p.z, 2.) / 2;
	pair.v = fmodf(p.y + 1, 2.) / 2;
	return (pair);
}
