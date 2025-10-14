/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:32:19 by afocant           #+#    #+#             */
/*   Updated: 2024/02/11 20:36:23 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_number(int n)
{
	char	d;
	char	u;

	d = ((n / 10) % 10) + '0';
	u = (n % 10) + '0';
	write(1, &d, 1);
	write(1, &u, 1);
}

void	print_numbers(int a, int b)
{
	put_number(a);
	ft_putchar(' ');
	put_number(b);
	if (a != 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_numbers(a, b);
			b++;
		}
		a++;
	}
}
