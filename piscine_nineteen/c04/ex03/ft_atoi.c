/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:06:41 by afocant           #+#    #+#             */
/*   Updated: 2024/07/10 00:00:38 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_negative(char *str)
{
	int	neg_flag;

	neg_flag = 0;
	while (ft_is_sign(*str))
	{
		if (*str == '-')
			neg_flag++;
		str++;
	}
	return (neg_flag % 2);
}

int	ft_atoi(char *str)
{
	int	neg_flag;
	int	n;

	while (ft_isspace(*str))
		str++;
	neg_flag = ft_is_negative(str);
	while (ft_is_sign(*str))
		str++;
	n = 0;
	while (*str && ft_isdigit(*str))
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	if (neg_flag % 2 == 1)
		n = -n;
	return (n);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int a;
	int b;

	if (argc != 2)
	{
		printf("args!");
		return (EXIT_FAILURE);
	}
	a = atoi(argv[1]);
	printf("the true atoi: %d\n", a);
	b = ft_atoi(argv[1]);
	printf(" my fake atoi: %d\n", b);
}
