/* ************************************************************************** */
/*                                                                            */
/*   0_parse_optionals.c                                  :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:38:42 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	has_material(char *s)
{
	if (ft_strncmp(s, "mat(", 4) == EXIT_SUCCESS)
		return (true);
	return (false);
}

bool	has_pattern(char *s)
{
	if (ft_strncmp(s, "pat(", 4) == EXIT_SUCCESS)
		return (true);
	return (false);
}

bool	has_texture(char *s)
{
	if (ft_strncmp(s, "tex(", 4) == EXIT_SUCCESS)
		return (true);
	return (false);
}

bool	has_rotation(char *s)
{
	if (ft_strncmp(s, "rota(", 5) == EXIT_SUCCESS)
		return (true);
	return (false);
}

t_object	parse_optionals(t_object o, char **line)
{
	if (is_just_whitespace(*line))
		return (o);
	if (has_rotation(*line))
		parse_rotation(&o, line);
	if (has_rotation(*line))
		parse_rotation(&o, line);
	if (has_rotation(*line))
		parse_rotation(&o, line);
	if (has_pattern(*line))
		parse_pattern(&o, line);
	if (has_material(*line))
		parse_material(&o, line);
	if (has_texture(*line))
		parse_texture(&o, line);
	if (has_scale_tex(*line))
		parse_scale_tex(&o, line);
	return (o);
}
