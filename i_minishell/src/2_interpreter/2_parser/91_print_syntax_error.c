/* ************************************************************************** */
/*                                                                            */
/*   91_print_syntax_error.c                              :::      ::::::::   */
/*   91_print_syntax_error.c                            :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:57:44 by afocant           #+#    #+#             */
/*   Updated: 2025/03/20 17:59:26 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

#include <unistd.h>

char	*get_tk_char(t_token *token)
{
	if (token->type == AMPERSAND)
		return ("&");
	if (token->type == D_AND)
		return ("&&");
	if (token->type == OR)
		return ("|");
	if (token->type == D_OR)
		return ("||");
	if (token->type == GREAT)
		return (">");
	if (token->type == D_GREAT)
		return (">>");
	if (token->type == LESS)
		return ("<");
	if (token->type == D_LESS)
		return ("<<");
	if (token->type == LEFT_PAREN)
		return ("(");
	if (token->type == RIGHT_PAREN)
		return (")");
	if (token->type == SEMICOLON)
		return (";");
	if (token->type == WORD)
		return (token->lexeme);
	return ("newline");
}

void	print_interact_mode_errmsg(t_token *token)
{
	char	*errmsg;

	errmsg = ft_cat_strs(3,
			"tiny: syntax error near unexpected token `",
			get_tk_char(token), "'\n");
	write(STDERR_FILENO, errmsg, ft_strlen(errmsg));
	free(errmsg);
}

void	print_script_mode_errmsg(t_token *token, t_shell *shell)
{
	char	*errmsg;
	char	*line_nb;

	errmsg = NULL;
	line_nb = ft_itoa(shell->line_nb);
	if (shell->flags & COMMAND_MODE)
		errmsg = ft_cat_strs(5, "tiny: -c: line ", line_nb,
				": syntax error near unexpected token `",
				get_tk_char(token), "'\n");
	else
		errmsg = ft_cat_strs(6, shell->script_file, ": line ", line_nb,
				": syntax error near unexpected token `",
				get_tk_char(token), "'\n");
	write(STDERR_FILENO, errmsg, ft_strlen(errmsg));
	free(errmsg);
	if (shell->flags & COMMAND_MODE)
		errmsg = ft_cat_strs(5, "tiny: -c: line ",
				line_nb, ": `", shell->input, "\'\n");
	else
		errmsg = ft_cat_strs(6, shell->script_file, ": line ",
				line_nb, ": `", shell->input, "\'\n");
	free(line_nb);
	write(STDERR_FILENO, errmsg, ft_strlen(errmsg));
	free(errmsg);
}

t_ast	*print_and_panic(t_token *token, t_ast *node, t_shell *shell)
{
	if (shell->flags & INTERACT_MODE)
		print_interact_mode_errmsg(token);
	else
		print_script_mode_errmsg(token, shell);
	syntax_panic(node, shell);
	return (node);
}
