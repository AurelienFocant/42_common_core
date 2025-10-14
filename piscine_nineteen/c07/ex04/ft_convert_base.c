/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:13:21 by afocant           #+#    #+#             */
/*   Updated: 2024/02/27 21:20:04 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_itoa_base(int n, char *base);
int		ft_strlen(char *str);

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	else if (c >= '\t' && c <= '\r')
		return (2);
	else
		return (0);
}

int	ft_isincorrect_base(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) < 2)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (2);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (3);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_find_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	n;
	int	i;
	int	len_base;
	int	neg_flag;

	i = 0;
	while (ft_isspace(nbr[i]))
		i++;
	neg_flag = 1;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			neg_flag *= -1;
		i++;
	}
	len_base = ft_strlen(base);
	n = 0;
	while (nbr[i] && (ft_find_index(nbr[i], base) > -1))
	{
		n = (n * len_base) + ft_find_index(nbr[i], base); 
		i++;
	}
	return (n * neg_flag);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*nbr_to;
	int		n;

	if (ft_isincorrect_base(base_from) || ft_isincorrect_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	nbr_to = ft_itoa_base(n, base_to);
	return (nbr_to);
}
