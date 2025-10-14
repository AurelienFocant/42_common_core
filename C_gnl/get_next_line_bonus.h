/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:41:18 by afocant           #+#    #+#             */
/*   Updated: 2024/06/04 19:45:51 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

# include "get_next_line_bonus.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/resource.h>
# include <sys/syslimits.h>

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char **stash);
char	*ft_join_stash_buff(char *stash, char *buf, size_t buf_len);
char	*ft_divide_stash(char **stash);

char	*ft_free_and_null(char **str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_extract_line(char *stash);
char	*ft_trim_stash(char *stash, char *start);

#endif
