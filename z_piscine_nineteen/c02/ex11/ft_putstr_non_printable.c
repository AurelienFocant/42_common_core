/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:31:35 by afocant           #+#    #+#             */
/*   Updated: 2024/02/17 12:41:21 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

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

void	ft_puthex(int dec)
{
	char	hex[3];
	int		i;
	int		tmp;

	i = 0;
	while (dec != 0)
	{
		tmp = dec % 16;
		if (tmp < 10)
			tmp += '0';
		else
			tmp += 'a' - 10;
		hex[i] = tmp;
		dec /= 16;
		i++;
	}
	hex[i] = '\0';
	ft_putchar('\\');
	if (dec < 16)
		ft_putstr("0");
	ft_putstr(hex);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_puthex(str[i]);
		}
		i++;
	}
	return ;
}

int main()
{
	char s[] = "hey\v";
	ft_putstr_non_printable(s);
}
