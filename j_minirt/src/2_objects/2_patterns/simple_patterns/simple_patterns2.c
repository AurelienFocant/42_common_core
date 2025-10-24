/* ************************************************************************** */
/*                                                                            */
/*   simple_patterns2.c                                   :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	stripe_at(t_simple_pattern *pat, t_point p)
{
	if ((int)floorf(p.x) % 2)
		return (pat->c1);
	return (pat->c2);
}

t_color	gradient_at(t_simple_pattern *pat, t_point p)
{
	t_color	distance;
	float	fraction;
	t_color	res;

	distance = sub_tuple(pat->c2, pat->c1);
	fraction = p.x - floorf(p.x);
	res = add_tuple(pat->c1, scalar_multi_tuple(fraction, distance));
	return (res);
}

t_color	ring_at(t_simple_pattern *pat, t_point p)
{
	float	res;

	res = sqrtf((float) powf(p.x, 2) + (float) powf(p.z, 2));
	if ((int)floorf(res) % 2)
		return (pat->c1);
	return (pat->c2);
}
