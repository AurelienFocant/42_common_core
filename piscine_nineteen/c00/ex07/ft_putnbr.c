/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:46:35 by afocant           #+#    #+#             */
/*   Updated: 2024/02/12 14:43:11 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// DOESNT HANDLE NEG NUMBERS

int	reverse_number(int n)
{
	int	rev_n;
	int	digit;

	rev_n = 0;
	while (n > 0)
	{
		digit = n % 10;
		rev_n = rev_n * 10 + digit;
		n /= 10;
	}
	return (rev_n);
}

void	print_digit(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	put_nbr(int nb)
{
	int	rev_n;
	int	digit;

	rev_n = reverse_number(nb);
	while (rev_n > 0)
	{
		digit = rev_n % 10;
		print_digit(digit);
		rev_n /= 10;
	}
}
