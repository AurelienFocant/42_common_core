/* ************************************************************************** */
/*                                                                            */
/*   color.c                                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tuple	add_colors(t_tuple c1, t_tuple c2)
{
	return (add_tuple(c1, c2));
}

t_tuple	sub_colors(t_tuple c1, t_tuple c2)
{
	return (sub_tuple(c1, c2));
}

t_tuple	scalar_multi_color(float scalar, t_tuple c)
{
	return (scalar_multi_tuple(scalar, c));
}

t_tuple	blend_colors(t_tuple c1, t_tuple c2)
{
	t_tuple	ret;

	ret = creat_tuple(c1.x * c2.x, c1.y * c2.y, c1.z * c2.z, c1.w * c2.w);
	return (ret);
}
