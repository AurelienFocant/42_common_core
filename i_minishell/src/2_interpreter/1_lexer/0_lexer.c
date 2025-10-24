/* ************************************************************************** */
/*                                                                            */
/*   0_lexer.c                                            :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:31:32 by afocant           #+#    #+#             */
/*   Updated: 2025/03/19 20:10:24 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "lexer.h"

#include <stdlib.h>

t_token	*lexical_analysis(char *line, t_shell *shell)
{
	char	*current;
	t_token	*token;

	current = line;
	while (*current)
	{
		skip_whitespace(&current);
		if (is_simple_operator(*current))
			token = tokenise_simple_operator(&current);
		else if (is_double_operator(*current))
			token = tokenise_double_operator(&current);
		else if (is_word_char(*current))
			token = tokenise_word(&current);
		else
			token = NULL;
		if (!token && *current != '\0')
			free_and_exit_shell("lexical error", EXIT_FAILURE, shell);
		add_back_tk(token, &(shell->token_stream));
	}
	add_back_tk(build_token(EOL, NULL), &(shell->token_stream));
	return (shell->token_stream);
}

t_token	*lexer(char *line, t_shell *shell)
{
	shell->token_stream = lexical_analysis(line, shell);
	if (shell->flags & DEBUG_FLAG)
		print_tk_stream(shell->token_stream);
	return (shell->token_stream);
}
