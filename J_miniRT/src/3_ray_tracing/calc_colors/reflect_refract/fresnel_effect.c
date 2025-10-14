/* ************************************************************************** */
/*                                                                            */
/*   fresnel_effect.c                                     :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	schlick(t_comps *comps)
{
	float	cos;
	float	n;
	float	sin2_t;
	float	cos_t;
	float	r0;

	cos = dot_product(comps->eyev, comps->normalv);
	if (comps->n1 > comps-> n2)
	{
		n = comps->n1 / comps->n2;
		sin2_t = powf(n, 2) * (1 - powf(cos, 2));
		if (sin2_t > 1.)
			return (1.);
		cos_t = sqrtf(1.0 - sin2_t);
		cos = cos_t;
	}
	r0 = powf((comps->n1 - comps->n2) / (comps->n1 + comps->n2), 2);
	return (r0 + (1 - r0) * powf(1 - cos, 5));
}
