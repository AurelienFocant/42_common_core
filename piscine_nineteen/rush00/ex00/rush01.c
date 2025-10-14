/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:08:19 by afocant           #+#    #+#             */
/*   Updated: 2024/02/11 17:57:54 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	check_for_exceptions(int a, int b)
{
	if (a < 0 || b < 0)
	{
		ft_putstr("Bad arguments\n");
		return (1);
	}
	else if (a == 0 || b == 0)
		return (1);
	else
		return (0);
}

void	print_line(int x, char c1, char c2, char c3)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if (j == 0)
			ft_putchar(c1);
		else if (j == x - 1)
			ft_putchar(c3);
		else
			ft_putchar(c2);
		j++;
	}
}

void	rush(int x, int y)
{
	int	i;

	if (check_for_exceptions(x, y))
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0)
		{
			print_line(x, '/', '*', '\\');
		}
		else if (i == y - 1)
		{
			print_line(x, '\\', '*', '/');
		}
		else
		{
			print_line(x, '*', ' ', '*');
		}
		ft_putchar('\n');
		i++;
	}
}
