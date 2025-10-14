/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:48:56 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:43:08 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_arg(int fd, char c, va_list *arg)
{
	int	count;

	count = 0;
	if (c == 'i' || c == 'd')
		count += ft_print_nbr_base(fd, va_arg(*arg, int), "0123456789");
	else if (c == 'u')
		count += ft_print_unsigned_nbr_base(fd, va_arg(*arg, int),
				"0123456789");
	else if (c == 'x')
		count += ft_print_unsigned_nbr_base \
				(fd, va_arg(*arg, int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_print_unsigned_nbr_base \
				(fd, va_arg(*arg, int), "0123456789ABCDEF");
	else if (c == 'p')
		count += ft_print_ptr(fd, va_arg(*arg, unsigned long long));
	else if (c == 's')
		count += ft_print_string(fd, va_arg(*arg, char *));
	else if (c == 'c')
		count += ft_print_char(fd, va_arg(*arg, int));
	else if (c == '%')
		count += ft_print_char(fd, '%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		a;
	va_list	arg;

	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			a = ft_parse_arg(1, *++format, &arg);
		else
			a = ft_print_char(1, *format);
		if (a < 0)
			return (-1);
		count += a;
		format++;
	}
	va_end(arg);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		count;
	int		a;
	va_list	arg;

	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			a = ft_parse_arg(fd, *++format, &arg);
		else
			a = ft_print_char(fd, *format);
		if (a < 0)
			return (-1);
		count += a;
		format++;
	}
	va_end(arg);
	return (count);
}
