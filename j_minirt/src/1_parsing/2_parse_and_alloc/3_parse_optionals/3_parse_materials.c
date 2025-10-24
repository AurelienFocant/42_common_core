/* ************************************************************************** */
/*                                                                            */
/*   2_parse_materials.c                                  :::      ::::::::   */
/*   3_parse_materials.c                                :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/20 19:03:19 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_material_type(char **line)
{
	if (**line == 'G')
	{
		if (*(*line + 5) == '1')
			return (GLASS1);
		if (*(*line + 5) == '2')
			return (GLASS2);
		if (*(*line + 5) == '3')
			return (GLASS3);
	}
	else if (**line == 'M')
	{
	}
	return (-1);
}

void	parse_mat(int type, t_object *o)
{
	if (type == GLASS1)
		glass1_object(o);
	if (type == GLASS2)
		glass2_object(o);
	if (type == GLASS3)
		glass3_object(o);
}

void	parse_material(t_object *o, char **line)
{
	adv_next_word(line);
	consume_paren(line);
	parse_mat(get_material_type(line), o);
}
