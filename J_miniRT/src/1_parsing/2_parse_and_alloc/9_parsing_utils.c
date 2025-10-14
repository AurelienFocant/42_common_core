/* ************************************************************************** */
/*                                                                            */
/*   9_parsing_utils.c                                    :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

void	adv_next_word(char **s)
{
	while (**s && !ft_isspace(**s) && **s != '(')
		(*s)++;
	while (**s && ft_isspace(**s))
		(*s)++;
}

void	consume_comma(char **s)
{
	while (**s && **s != ',')
		(*s)++;
	if (**s)
		(*s)++;
}

t_vec	get_next_vector(char **s)
{
	float	x;
	float	y;
	float	z;

	x = ft_atof(*s);
	consume_comma(s);
	y = ft_atof(*s);
	consume_comma(s);
	z = ft_atof(*s);
	adv_next_word(s);
	return (vector(x, y, z));
}

float	get_next_float(char **s)
{
	float	f;

	f = (float) ft_atof(*s);
	adv_next_word(s);
	return (f);
}

t_color	get_next_color(char **line)
{
	t_vec	v;

	v = get_next_vector(line);
	return (color(v.x / 255., v.y / 255., v.z / 255.));
}
