/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:24:54 by afocant           #+#    #+#             */
/*   Updated: 2024/02/27 11:52:47 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_invalid_base(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] == ' ')
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

int	find_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if(c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg_flag;
	int	n;
	int	len;

	if (check_invalid_base(base))
		return (0);
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	neg_flag = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_flag *= -1;
		i++;
	}
	len = ft_strlen(base);
	n = 0;
	while (str[i] && (find_index(str[i], base) > -1))
	{
		n = (n * len) + (find_index(str[i], base));
		i++;
	}
	return (n * neg_flag);
}

int main()
{
	printf("%i\n", ft_atoi_base("@!@5@@@", "!@"));
}
