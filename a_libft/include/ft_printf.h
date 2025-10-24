/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:46:28 by afocant           #+#    #+#             */
/*   Updated: 2025/01/28 10:53:37 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_print_char(int fd, char c);
int	ft_print_string(int fd, char *s);
int	ft_getlen(char *s);

int	ft_print_nbr_base(int fd, int n, char *base);
int	ft_print_neg_nbr_base(int fd, int n, char *base);
int	ft_print_unsigned_nbr_base(int fd, unsigned int n, char *base);

int	ft_print_ptr_base(int fd, unsigned long long n, char *base);
int	ft_print_ptr(int fd, unsigned long long n);

int	ft_parse_arg(int fd, char c, va_list *arg);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_printf(const char *format, ...);

#endif
