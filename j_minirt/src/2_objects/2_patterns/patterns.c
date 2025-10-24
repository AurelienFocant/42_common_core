/* ************************************************************************** */
/*                                                                            */
/*   patterns.c                                           :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	pattern_at_object(t_pattern *pat, t_object *o, t_point world_space)
{
	t_point	object_space;
	t_point	pattern_space;

	object_space = multi_mat4_tuple(inverse_mat4(o->trans), world_space);
	pattern_space = multi_mat4_tuple(inverse_mat4(pat->trans), object_space);
	if (pat->type == SIMPLE)
		return (simple_pat(&pat->simp_pat, pattern_space));
	else if (pat->type == UV_PAT)
		return (texture_map(&pat->uv_pat, o, pattern_space));
	printf("no pattern found\n");
	return (color(0, 0, 0));
}
