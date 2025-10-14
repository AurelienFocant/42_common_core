#include "picoshell.h"

t_node	*parse_prefix(t_token **token)
{
	t_node	*redir;
	t_node	*new_redir;

	if (!*token)
		return (NULL);
	redir = NULL;
	while (true)
	{
		if (is_redir_tk(token))
		{
			new_redir = build_redir_node(token);
			redir_add_back(&redir, new_redir);
		}
		else
			break;
	}
	return (redir);
}

t_node	*parse_cmd(t_token **token, t_node	*prefix)
{
	t_node	*cmd;

	if (!*token || (*token)->class != WORD)
		return (prefix);
	cmd = ft_calloc(1, sizeof(t_node));
	cmd->type = CMD;
	cmd->data.cmd.string = parse_word(token);
	consume(token);
	cmd->data.cmd.next = prefix;
	return (cmd);
}

void	parse_suffix(t_token **token, t_node **cmd)
{
	t_node	*redir;
	t_node	*new_redir;

	if (!*token)
		return ;
	redir = NULL;
	while (true)
	{
		if (is_redir_tk(token))
		{
			new_redir = build_redir_node(token);
			redir_add_back(&redir, new_redir);
		}
		else if (is_word_tk(token))
			modify_cmd_string(token, cmd);
		else
			break;
	}
	// add_suffix_to_cmd(new_redir, cmd);
}

t_node	*parse_simple_cmd(t_token **token)
{
	t_node	*prefix;
	t_node	*cmd;

	prefix = parse_prefix(token);
	cmd = parse_cmd(token, prefix);
	parse_suffix(token, &cmd);
	return (cmd);
	
}
