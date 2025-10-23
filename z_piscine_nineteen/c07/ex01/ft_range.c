/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:26:03 by afocant           #+#    #+#             */
/*   Updated: 2024/02/27 22:26:43 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_size(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

int	*ft_range(int min, int max)
{
	int	*p;
	int	size;
	int	i;

	if (min >= max)
	{
		p = NULL;
		return (p);
	}
	size = get_size(min, max);
	p = malloc(sizeof(int) * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (min < max)
		p[i++] = min++;
	return (p);
}
