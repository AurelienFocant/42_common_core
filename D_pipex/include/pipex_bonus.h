/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 01:13:23 by afocant           #+#    #+#             */
/*   Updated: 2024/09/23 14:49:12 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

# include "pipex_bonus.h"
# include "libft.h"

# define FALSE	0
# define TRUE	1

# define CHILD	0

# define READ		0
# define WRITE		1
# define APPEND		2

# define PROG_NAME	1 
# define IO_FILES	2 

typedef struct s_context
{
	int				argc;
	char			**argv;
	char			**envp;
	char			**path;
	unsigned int	heredoc;
	int				nb_of_pipes;
	int				nb_of_cmds;
	int				curr_cmd_nb;
	char			**cmd;
	char			*executable;
	int				files_fd[2];
	int				*pipes_fd;
}				t_context;

/*----------------  parsing_cmd_bonus.c  ---------------*/
void		ft_parse_quotes(char *str);
char		**ft_parse_cmd(char *arg);

/*----------------  path_and_cmd_extraction_bonus.c  ---------------*/
char		*ft_cat_path_cmd(char **path, char *cmd);
char		*ft_prepend_path_cmd(char **path, char *cmd);
char		*ft_find_full_path(char **path, char *cmd);
void		ft_find_executable(t_context *context);

/*----------------  pipex_bonus.c  ---------------*/
void		ft_execute_child(t_context *context);
pid_t		sys_fork(void);
void		ft_pipex(t_context *context);
void		ft_prepare_pipe(t_context *context);

/*----------------  prepare_context_bonus.c  ---------------*/
int			ft_check_heredoc(int argc, char **argv);
char		**ft_get_path(char **envp);
t_context	ft_initialise_context(int argc, char **argv, char **envp);

/*----------------  setup_redirection_bonus.c  ---------------*/
void		ft_redirection_first_child(t_context *context);
void		ft_redirection_last_child(t_context *context);
void		ft_redirection_middle_children(t_context *context);
void		ft_setup_redirection(t_context *context);

/*----------------  utils_check_files_bonus.c  ---------------*/
int			ft_check_if_cmd_is_executable(char *arg);
int			ft_check_argc(int argc);
int			ft_check_valid_files(char *infile, char *outfile);

/*----------------  utils_cleanup_bonus.c  ---------------*/
void		ft_print_error(char *error_msg, char *str_error);
int			ft_cmd_perror(char *error_msg, int my_errno, int exitcode);
int			ft_perror_exit(char *error, int my_errno, int errnb);
void		ft_wait_for_all_children(t_context *context);
void		ft_close_pipes(t_context *context);

/*----------------  utils_redirection_bonus.c  ---------------*/
int			ft_open_file(char *file, int mode);
int			ft_prepare_heredoc(t_context *context);
void		ft_duplicate_fds(t_context *context);
void		ft_close_heredoc(t_context *context);

#endif
