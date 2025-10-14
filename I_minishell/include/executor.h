/* ************************************************************************** */
/*                                                                            */
/*   executor.h                                           :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:07:49 by afocant           #+#    #+#             */
/*   Updated: 2025/03/26 13:38:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

typedef struct s_io
{
	int		input;
	int		output;
	int		to_close;
	int		prev_pipe_read;
}	t_io;

#endif
