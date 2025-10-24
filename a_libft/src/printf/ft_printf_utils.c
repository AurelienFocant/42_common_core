/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:48:25 by afocant           #+#    #+#             */
/*   Updated: 2025/01/28 10:52:10 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int fd, char c)
{
	if (write(fd, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_print_string(int fd, char *s)
{
	int	count;

	if (!s)
		return (ft_print_string(fd, "(null)"));
	count = 0;
	while (*s)
	{
		if (write(fd, s++, 1) < 0)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_getlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
