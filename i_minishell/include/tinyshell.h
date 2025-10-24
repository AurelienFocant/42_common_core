/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:51:18 by afocant           #+#    #+#             */
/*   Updated: 2025/04/01 13:58:53 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TINYSHELL_H
# define TINYSHELL_H

# include "lexer.h"
# include "parser.h"
# include "executor.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>

// # define BIT(i)	(1 << i)
// // SHELL FLAGS
// # define INTERACT_MODE	BIT(1)
// # define COMMAND_MODE	BIT(2)
// # define SCRIPT_MODE		BIT(3)
// # define DEBUG_FLAG		BIT(4)
// # define GRAPH_FLAG		BIT(5)
// # define SYNTAX_PANIC	BIT(6)
// # define HEREDOC_SIGINT	BIT(7)
// # define MALLOC_FAILED	BIT(8)
// # define EXEC_PANIC		BIT(9)
// # define ENOENT_CMD		BIT(10)
// # define EACCES_CMD		BIT(11)
// # define ISDIR_CMD		BIT(12)
// # define ENOENT_FILE		BIT(13)
// # define EACCES_FILE		BIT(14)
// # define HAS_PIPE		BIT(15)

// SHELL FLAGS
# define INTERACT_MODE		000001
# define COMMAND_MODE		000002
# define SCRIPT_MODE		000004
# define DEBUG_FLAG			000010
# define GRAPH_FLAG			000020
# define SYNTAX_PANIC		000040
# define HEREDOC_SIGINT		000100
# define MALLOC_FAILED		000200
# define EXEC_PANIC			000400
# define ENOENT_CMD			001000
# define EACCES_CMD			002000
# define ISDIR_CMD			004000
# define ENOENT_FILE		010000
# define EACCES_FILE		020000
# define HAS_PIPE			040000

// EXIT_CODES
# define INVALID_OPTION	2
# define SYNTAX_ERROR	2

# define EACCES_ERROR	126
# define ENOENT_ERROR	127

// MISC
# define NO_FILE		-1
# define SYSCALL_ERROR	-1
# define CHILD			0

typedef unsigned int	t_exit_code;

typedef struct s_strlst	t_strlst;

typedef struct s_strlst
{
	char		*str;
	t_strlst	*next;
}	t_strlst;

typedef struct s_shell
{
	int			std_in;
	int			std_out;

	uint16_t	flags;
	t_strlst	*envp;
	char		*histfile;

	char		*script_file;
	int			line_nb;

	char		*input;
	t_token		*token_stream;
	t_ast		*ast_root;

	pid_t		last_child;
	int			nb_of_children;
	t_exit_code	exit_code;
}	t_shell;

/*----------------  src/1_init  ---------------*/
/* File: 0_init_shell.c */
void			init_shell(char **envp, t_shell *shell);

/* File: 1_parse_options.c */
void			parse_args(int argc, char **argv, t_shell *shell);

/*----------------  src/2_interpreter  ---------------*/
/* File: 0_interpreter.c */
void			script_mode(char *file, t_shell *shell);
void			command_mode(char *line, t_shell *shell);
void			interactive_mode(t_shell *shell);
t_exit_code		command_line_interpreter(char *line, t_shell *shell);

/*----------------  src/2_interpreter/1_lexer  ---------------*/
/* File: 0_lexer.c */
t_token			*lexical_analysis(char *line, t_shell *shell);
t_token			*lexer(char *line, t_shell *shell);

/* File: 1_single_op.c */
bool			is_simple_operator(char c);
t_token			*tokenise_simple_operator(char **current);

/* File: 2_double_op.c */
bool			is_double_operator(char c);
t_token			*tokenise_double_operator(char **current);

/* File: 3_words.c */
size_t			get_word_len(char *start, char *current);
t_token			*tokenise_word(char **current);

/* File: 4_words_utils.c */
bool			is_quote(char c);
bool			is_metacharacter(char c);
bool			is_word_char(char c);

/* File: 8_utils.c */
void			skip_whitespace(char **str);
char			advance_tk(char **current);
t_token			*build_token(t_tk_type type, char *lexeme);
void			add_back_tk(t_token *new, t_token **list);

/* File: 9_print_tk_lst.c */
void			print_tk_stream(t_token *list);

/*----------------  src/2_interpreter/2_parser  ---------------*/
/* File: 0_parser.c */
t_ast			*parse_command_line(t_token **tokens, t_shell *shell);
t_ast			*parser(t_token *tokens, t_shell *shell);

/* File: 1_cond_line.c */
t_ast			*parse_conditional_line(t_token **token, t_shell *shell);

/* File: 2_pipeline.c */
t_ast			*parse_pipeline(t_token **token, t_shell *shell);

/* File: 3_subshell.c */
t_ast			*parse_subshell(t_token **token, t_shell *shell);

/* File: 4_cmd.c */
t_ast			*parse_prefix(t_token **token, t_shell *shell);
t_ast			*parse_suffix(t_token **token,
					t_cmd *cmd, t_ast **prefix, t_shell *sh);
t_ast			*parse_command(t_token **token, t_shell *shell);

/* File: 5_cmd_options.c */
char			*realloc_cmd_name(t_token **token,
					char *str, char ***name, t_shell *sh);

/* File: 6_redir.c */
void			redir_add_front(t_ast *new, t_ast **prefix);
t_ast			*build_redirection(t_token **token,
					t_token *previous, t_shell *shell);
t_ast			*parse_redirect_list(t_token **token,
					t_ast **redir_lst, t_shell *shell);

/* File: 70_heredoc.c */
t_ast			*build_heredoc_node(t_token **token, t_shell *shell);

/* File: 71_heredoc_utils.c */
char			has_quote(char *s);
int				hdoc_interrupted(int *pipev, char *line, t_shell *shell);
int				hdoc_unexp_eof(char *delim);
int				hdoc_pipe_error(t_shell *shell);

/* File: 80_utils.c */
t_token			*advance(t_token **token);
bool			match(t_tk_type tk_type, t_token **token);

/* File: 81_utils2.c */
bool			is_tk_word(t_token *token);
bool			is_tk_redir(t_token *token);
bool			is_tk_cond(t_token *token);
bool			is_tk_pipe(t_token *token);

/* File: 90_syntax_error.c */
t_ast			*syntax_panic(t_ast *node, t_shell *shell);
void			*syntax_malloc_failed(t_shell *shell);

/* File: 91_print_syntax_error.c */
char			*get_tk_char(t_token *token);
void			print_interact_mode_errmsg(t_token *token);
void			print_script_mode_errmsg(t_token *token, t_shell *shell);
t_ast			*print_and_panic(t_token *token, t_ast *node, t_shell *shell);

/* File: 92_redir_errors.c */
char			*print_file_error(char *sh,
					char *filename, char *msg, t_shell *shell);
void			check_redir_errors(char *filename, t_shell *shell);

/*----------------  src/2_interpreter/3_executor  ---------------*/
/* File: 0_executor.c */
t_exit_code		wait_for_children(t_shell *shell);
void			visit_node(t_ast *node, t_io *io, t_shell *shell);
t_exit_code		executor(t_ast *ast, t_shell *shell);

/* File: 1_cond.c */
void			visit_cond(t_cond cond, t_io *io, t_shell *shell);

/* File: 2_pipe.c */
void			visit_pipe(t_pipe pipe_nd, t_io *io, t_shell *shell);

/* File: 3_cmd.c */
void			visit_cmd(t_cmd *cmd, t_io *io, t_shell *shell);

/* File: 4_cmd_path.c */
char			*search_path(char *cmd, t_shell *shell);

/* File: 5_builtin.c */
bool			is_builtin(char *cmd);
void			exec_builtin(t_cmd cmd, t_io *io, t_shell *shell);

/* File: 6_redirs.c */
void			visit_redir(t_redir *redir, t_io *io, t_shell *shell);

/* File: 7_heredoc.c */
void			visit_heredoc(t_hdoc hdoc, t_io *io, t_shell *shell);

/* File: 8_utils.c */
void			restore_std_io(t_shell *shell);
void			duplicate_fds(t_io *io);

/* File: 9_exec_errors.c */
void			check_path_errors(char *cmd, t_shell *shell);
char			*exec_error(char *cmd, t_shell *shell);

/*----------------  src/3_expander  ---------------*/
/* File: 0_expand.c */
bool			has_expansion(char *str);
void			perform_expansions(char ***strv, t_shell *shell);

/* File: 1_tilde_exp.c */
void			tilde_expansion(char **s, t_shell *shell);

/* File: 20_param_expand.c */
char			*get_expanded_value(char *param_word, t_shell *shell);
char			*get_param_w(char *s, t_shell *shell);
void			parameter_expansion(char **str, t_shell *shell);

/* File: 21_param_expand_counting.c */
void			param_exp(char *res, char *str, t_shell *shell);

/* File: 22_param_expand_copying.c */
size_t			get_expansion_len(char *str, t_shell *shell);

/* File: 30_word_splitting.c */
t_strlst		*word_splitting(
					t_strlst **head,
					t_strlst **lst,
					t_strlst **previous,
					t_shell *shell);

/* File: 310_word_splitting_split.c */
char			**split_words(char *s, char c, t_shell *shell);

/* File: 311_word_splitting_fill.c */
char			**fill_strs(char *s, char c, char **split_s, int strs_count);

/* File: 4_filename_exp.c */
void			filename_expansion(char **str, t_shell *shell);

/* File: 5_quote_removal.c */
void			quote_removal(char **str, t_shell *shell);

/*----------------  src/4_builtins  ---------------*/
/* File: echo.c */
t_exit_code		echo_builtin(t_cmd cmd);

/* File: env.c */
t_exit_code		env_builtin(t_shell *shell);

/* File: exit.c */
t_exit_code		exit_builtin(t_cmd cmd, t_shell *shell);

/* File: pwd.c */
t_exit_code		pwd_builtin(t_shell *shell);

/* File: unset.c */
t_exit_code		unset_builtin(t_cmd cmd, t_shell *shell);

/*----------------  src/4_builtins/cd  ---------------*/
/* File: cd_1.c */
char			*get_current_dir(t_shell *shell);
char			*get_target_directory(t_cmd cmd, t_shell *shell, t_exit_code *status);
void			print_chdir_error(char *target_dir);
t_exit_code		cd_builtin(t_cmd cmd, t_shell *shell);

/* File: cd_2.c */
void			update_env_var(char *name, char *value, t_shell *shell);
void			update_pwd_variables(char *old_pwd, t_shell *shell);

/* File: cd_3.c */
char			*handle_home_dir(t_exit_code *status, t_shell *shell);
char			*handle_oldpwd(t_exit_code *status, t_shell *shell);
int				handle_current_wd(char **pwd_str, t_shell *shell);
int				handle_getcwd_error(char *buf, char **pwd_str, t_shell *shell);
int				handle_enoent_error(char *buf, char **pwd_str, t_shell *shell);

/*----------------  src/4_builtins/export  ---------------*/
/* File: export.c */
void			update_existing_env_var(
					t_strlst *var, char *new_var, t_shell *sh);
t_exit_code		export_builtin(t_cmd cmd, t_shell *shell);

/* File: export_concat.c */
void			cat_env_var(char *assign, t_shell *shell);

/* File: export_no_args.c */
void			export_no_arg(t_shell *shell);

/* File: export_utils.c */
bool			is_identifier(char *word, int *j, bool *error);
char			*has_assignment(char *word, int *i);

/*----------------  src/5_signals  ---------------*/
/* File: interact_mode_signals.c */
void			init_interactive_mode_signals(void);

/* File: signals.c */
void			sigint_hdoc_handler(int signum);
void			set_signals_waiting_parent(void);
void			reset_signals_default(void);

/*----------------  src/6_history  ---------------*/
/* File: populate_history.c */
bool			read_histfile(t_shell *shell);
bool			populate_histfile(char *line, char *histfile);

/*----------------  src/8_utils  ---------------*/
/* File: exit_shell.c */
void			free_tokens(t_token **token_stream);
void			free_shell(t_shell *shell);
void			free_and_exit_shell(char *msg,
					t_exit_code exit_code, t_shell *shell);

/* File: find_env_var.c */
char			*extract_env_var_name(char *start, char *end, t_shell *shell);
char			*find_env_var_value(char *str, t_shell *shell);
t_strlst		*find_env_var(char *str, t_shell *shell);

/* File: options.c */
int				count_dashes(char *arg);
char			*get_first_non_option(char **arg);

/*----------------  src/8_utils/free_ast  ---------------*/
/* File: free_ast2.c */
void			*free_cond(t_cond cond);
void			*free_pipe(t_pipe pipe);
void			*free_cmd(t_cmd cmd);
void			*free_redir(t_redir redir);
void			*free_heredoc(t_hdoc hdoc);

/* File: free_ast.c */
void			*free_node(t_ast *node);
t_ast			*free_ast(t_ast **ast_root);

/*----------------  src/8_utils/strlst  ---------------*/
/* File: strlst_to_strv.c */
void			free_null_strlst(t_strlst **lst);
void			free_strlst(t_strlst **strlst);
char			**strlst_to_strv(t_strlst *strlst);

/* File: strv_to_strlst.c */
t_strlst		*build_strlst(char *str);
t_strlst		*strlstlast(t_strlst *lst);
void			strlstadd_back(t_strlst **lst, t_strlst *new);
t_strlst		*strv_to_strlst(char **strv);

/*----------------  src/9_draw_ast  ---------------*/
/* File: graph.c */
void			write_node_connection(int fd, int parent_id, int child_id);
void			write_node(int fd, t_ast *ast, int *node_id);
bool			visualizer(t_ast*ast);

/* File: put_label_1.c */
void			print_cmd_label(int fd, t_ast *ast, int my_id);
void			print_cond_label(int fd, t_ast *ast, int my_id);
void			print_redir_label(int fd, t_ast *ast, int my_id);

/* File: put_label_2.c */
void			print_heredoc_label(int fd, t_ast *ast, int my_id);
void			write_label(int fd, t_ast *ast, int my_id);

/* File: write_node_1.c */
void			write_cmd_node(int fd, t_ast *ast, int *node_id, int my_id);
void			write_pipe_node(int fd, t_ast *ast, int *node_id, int my_id);
void			write_cond_node(int fd, t_ast *ast, int *node_id, int my_id);
void			write_redir_node(int fd, t_ast *ast, int *node_id, int my_id);

/* File: write_node_2.c */
void			write_heredoc_node(int fd, t_ast *ast, int *node_id, int my_id);
void			write_subsh_node(int fd, t_ast *ast, int *node_id, int my_id);

#endif
