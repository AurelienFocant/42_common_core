/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:28:58 by afocant           #+#    #+#             */
/*   Updated: 2024/02/28 22:15:32 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nbrlen_base(unsigned int n, int len_base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= len_base;
		len++;
	}
	return (len);
}

unsigned int	ft_isnegative(int n)
{
	unsigned int	un_n;

	if (n == -2147483648)
	{
		un_n = 2147483648; 
	}
	else if (n < 0)
	{
		un_n = -n;
	}
	else
		un_n = n;
	return (un_n);
}

int	ft_needs_a_minus(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa_base(int n, char *base)
{
	unsigned int	un_n;
	char			*nbr;
	int				len_nbr;
	int				len_base;
	int				i;

	un_n = ft_isnegative(n);
	len_base = ft_strlen(base);
	len_nbr = ft_needs_a_minus(n);
	len_nbr = len_nbr + ft_nbrlen_base(un_n, len_base);
	nbr = malloc(sizeof(char) * (len_nbr + 1));
	if (nbr == NULL)
		return (NULL);
	i = 0;
	while (i < len_nbr)
	{
		nbr[len_nbr - 1 - i] = base[un_n % len_base]; 
		un_n /= len_base;
		i++;
	}
	if (n < 0)
		nbr[0] = '-';
	nbr[len_nbr] = '\0';
	return (nbr);
}
