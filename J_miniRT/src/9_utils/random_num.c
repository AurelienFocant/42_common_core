/* ************************************************************************** */
/*                                                                            */
/*   random_num.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: alama   <alama@student.s19.be>               +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:30:57 by afocant           #+#    #+#             */
/*   Updated: 2025/07/16 23:31:19 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	sequence(float *tab, int *tab_pos, int tab_size)
{
	float	res;

	if (*tab_pos >= tab_size)
	{
		*tab_pos = 0;
		return (tab[*tab_pos]);
	}
	res = tab[*tab_pos];
	*tab_pos = *tab_pos + 1;
	return (res);
}

float	calc_jitter(void)
{
	float		tab[5];
	static int	tab_pos = 0;

	tab[0] = 0.3;
	tab[1] = 0.7;
	tab[2] = 0.9;
	tab[3] = 0.1;
	tab[4] = 0.5;
	return (sequence(tab, &tab_pos, 5));
}
