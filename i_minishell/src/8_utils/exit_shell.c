/* ************************************************************************** */
/*                                                                            */
/*   exit_shell.c                                         :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:16:53 by afocant           #+#    #+#             */
/*   Updated: 2025/03/21 11:27:27 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "lexer.h"

#include <stdlib.h>
#include <readline/readline.h>

void	free_tokens(t_token **token_stream)
{
	t_token	*token;
	t_token	*tmp;

	token = *token_stream;
	while (token)
	{
		tmp = token;
		token = token->next;
		if (tmp->lexeme)
			ft_free_null((void **) &(tmp->lexeme));
		ft_free_null((void **) &tmp);
	}
	*token_stream = NULL;
}

void	free_shell(t_shell *shell)
{
	if (!(shell->flags & COMMAND_MODE))
		if (shell->input)
			ft_free_null((void **) &(shell->input));
	if (shell->histfile)
		ft_free_null((void **) &(shell->histfile));
	if (shell->token_stream)
		free_tokens(&(shell->token_stream));
	if (shell->ast_root)
		free_ast(&(shell->ast_root));
	if (shell->envp)
		free_strlst(&(shell->envp));
	close(shell->std_in);
	close(shell->std_out);
}

void	free_and_exit_shell(char *msg, t_exit_code exit_code, t_shell *shell)
{
	if (msg)
		ft_dprintf(STDOUT_FILENO, "%s\n", msg);
	free_shell(shell);
	rl_clear_history();
	shell->exit_code = exit_code;
	exit(shell->exit_code);
}
