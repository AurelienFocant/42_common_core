/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:53:03 by slangero          #+#    #+#             */
/*   Updated: 2025/03/20 17:37:11 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinyshell.h"
#include "libft.h"

#include <unistd.h>
#include <fcntl.h>

static void	print_escaped_string(int fd, char *str)
{
	while (*str)
	{
		if (*str == '"' || *str == '\\')
			ft_dprintf(fd, "\\");
		ft_dprintf(fd, "%c", *str);
		str++;
	}
}

void	print_cmd_label(int fd, t_ast *ast, int my_id)
{
	int		i;

	i = 0;
	ft_dprintf(fd, "\tnode%d [label=\"CMD\\n", my_id);
	if (ast->cmd.name[i])
		print_escaped_string(fd, ast->cmd.name[i]);
	i++;
	while (ast->cmd.name[i])
	{
		ft_dprintf(fd, " ");
		print_escaped_string(fd, ast->cmd.name[i]);
		i++;
	}
	ft_dprintf(fd, "\"];\n");
}

void	print_cond_label(int fd, t_ast *ast, int my_id)
{
	if (ast->cond.type == AND_IF)
		ft_dprintf(fd, "\tnode%d [label=\"AND\"];\n", my_id);
	else
		ft_dprintf(fd, "\tnode%d [label=\"OR\"];\n", my_id);
}

static char	*get_redir_operator(t_redir_type type)
{
	if (type == IN)
		return ("<");
	if (type == OUT)
		return (">");
	if (type == APPEND)
		return (">>");
	return ("?");
}

void	print_redir_label(int fd, t_ast *ast, int my_id)
{
	char	*operator;

	operator = get_redir_operator(ast->redir.type);
	ft_dprintf(fd, "\tnode%d [label=\"REDIR\n %s%s\n\"];\n",
		my_id, operator, ast->redir.filename);
}
