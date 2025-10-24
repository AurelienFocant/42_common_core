/* ************************************************************************** */
/*                                                                            */
/*   90_syntax_error.c                                    :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:03:50 by afocant           #+#    #+#             */
/*   Updated: 2025/03/18 14:10:18 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"

#include <unistd.h>

t_ast	*syntax_panic(t_ast *node, t_shell *shell)
{
	shell->flags |= SYNTAX_PANIC;
	shell->exit_code = SYNTAX_ERROR;
	return (node);
}

void	*syntax_malloc_failed(t_shell *shell)
{
	shell->flags |= MALLOC_FAILED;
	write(2, "malloc failed\n", 14);
	return (NULL);
}
