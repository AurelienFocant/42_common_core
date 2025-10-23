/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:12:45 by afocant           #+#    #+#             */
/*   Updated: 2024/02/21 21:00:14 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *str)
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

void	ft_putlong_base(int nb, char *base)
{
	int		max;
	char	digit;
	long	nbr;

	if (ft_check_base(base))
		return ;
	nbr = nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	max = ft_strlen(base);
	if (nbr >= max)
	{
		ft_putlong_base(nbr / max, base);
	}
	digit = base[nbr % max];
	write(1, &digit, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		max;
	char	digit;

	if (ft_check_base(base))
		return ;
	if (nbr == -2147483648)
	{
		return (ft_putlong_base(nbr, base));
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	max = ft_strlen(base);
	if (nbr >= max)
	{
		ft_putnbr_base(nbr / max, base);
	}
	digit = base[nbr % max];
	write(1, &digit, 1);
}
