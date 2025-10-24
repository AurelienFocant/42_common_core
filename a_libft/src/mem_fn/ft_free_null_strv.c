/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_null_strv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:16:33 by afocant           #+#    #+#             */
/*   Updated: 2024/09/23 13:16:35 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_null_strv(char ***strv)
{
	size_t	i;

	i = 0;
	while ((*strv)[i])
	{
		ft_free_null((void **) *strv + i);
		i++;
	}
	ft_free_null((void **) strv);
}
