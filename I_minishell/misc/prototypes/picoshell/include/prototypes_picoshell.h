#ifndef PROTOTYPES_PICOSHELL_H
# define PROTOTYPES_PICOSHELL_H

#include "picoshell.h"

/*----------------  src  ---------------*/
/* File: 0_main.c */
char	*expand(char *var, t_shell *shell);
t_exit_code	print_error(char *msg);
void	init_shell(char **envp, t_shell *shell);


/*----------------  src/1_interpreter/1_lexer/utils  ---------------*/
/* File: list_utils.c */
t_token	*last_token(t_token *lst);
void	add_back(t_token **token_list, t_token *new_token);
void	print_linked_list(t_token *token_list);


/*----------------  src/1_interpreter/1_lexer  ---------------*/
/* File: char_types.c */
int	is_operator(char c);
int	is_metacharacter(char c);
int	is_whitespace(char c);
int	is_eol(char *current);

/* File: lexer.c */
t_token	*build_token(t_tk_class class, char *lexeme);
t_token	*lexer(char *input);

/* File: token_utils.c */
char	peek(char *current);
int	advance(char **current);
void	print_token_class(t_token *token);

/* File: tokenise_operators.c */
int	is_single_operator(char c);
t_token	*tokenise_single_operator(char **current);
int	is_double_operator(char c);
t_token *tokenise_double_operator(char **current);

/* File: tokenise_words.c */
int	is_word(char c);
char	*extract_lexeme(char *start, char *end);
t_token	*tokenise_word(char **current);


/*----------------  src/1_interpreter/2_parser  ---------------*/
/* File: parser.c */
bool	consume(t_token **token);
bool	match(t_token **token, t_tk_class class);
t_node	*parser(t_token **tokens);


/*----------------  src/1_interpreter/2_parser/visualizer  ---------------*/
/* File: visualize.c */
void	ft_write_node(int fd, t_node *tree, int *node_id);
bool	visualizer(t_node *tree);


/*----------------  src/1_interpreter/2_parser  ---------------*/
/* File: parse_pipes.c */
t_node	*build_pipe_node(t_node *left, t_node *right);
bool	is_tk_pipe(t_token **token);
t_node	*parse_pipeline(t_token **token);

/* File: parse_redirs.c */
bool	is_redir_tk(t_token **token);
t_redir_type	redir_type(t_token **token);
t_node	*get_last(t_node *redir);
bool	redir_add_back(t_node **node, t_node *new_node);
t_node	*build_redir_node(t_token **token);

/* File: parse_cmd.c */
t_node	*parse_prefix(t_token **token);
t_node	*parse_cmd(t_token **token, t_node	*prefix);
void	parse_suffix(t_token **token, t_node **cmd);
t_node	*parse_simple_cmd(t_token **token);

/* File: parse_cmd_utils.c */
char	*parse_word(t_token **token);
char	*join_words(char *w1, char *w2);
void	modify_cmd_string(t_token **token, t_node **cmd);
bool	is_word_tk(t_token **token);


/*----------------  src/1_interpreter/4_executor  ---------------*/
/* File: execute_redir.c */
bool	duplicate_fd(t_ctxt *ctxt);
bool	redirect_input(char *filename, t_ctxt *ctxt);
bool	redirect_output(char *filename, t_ctxt *ctxt);
t_exit_code	execute_redir(t_redir redirnode, t_ctxt *ctxt, t_shell *shell);

/* File: interpreter.c */
t_exit_code	execute_node(t_node	*node, t_ctxt *ctxt, t_shell *shell);
t_exit_code	execute_pipe(t_pipe	pipenode, t_ctxt *ctxt, t_shell *shell);
void	execute_builtin(char *cmd, t_shell *shell);
t_exit_code	executer(t_node *ast, t_shell *shell);

/* File: execute_cmd.c */
t_exit_code	execute_cmd(t_cmd cmdnode, t_ctxt *ctxt, t_shell *shell);
void	execute_builtin(char *cmd, t_shell *shell);
bool	is_builtin(char *cmd);
t_exit_code	fork_exec(char *exec_path, t_cmd cmdnode, t_ctxt *ctxt, t_shell *shell);


/*----------------  src/1_interpreter  ---------------*/
/* File: 0_interpreter.c */
t_exit_code	command_mode(char *line, t_shell *shell);
t_exit_code	script_mode(char *filename, t_shell *shell);
t_exit_code	interactive_mode(t_shell *shell);
t_exit_code	command_line_interpreter(char *line, t_shell *shell);


/*----------------  src/2_builtins  ---------------*/
/* File: exit.c */
t_exit_code	ft_exit(t_exit_code exit_code);


/*----------------  src/3_history  ---------------*/
/* File: history.c */
bool	write_to_hist_file(char *line, t_shell *shell);
bool	populate_history(char *line, t_shell *shell);
void	read_history_file(t_shell *shell);

#endif
