#include "picoshell.h"

char	*parse_word(t_token **token)
{
	char *word;

	// protect if not TK_WORD
	word = ft_strdup((*token)->lexeme);
	// protect strdup
	return (word);
}

char	*join_words(char *w1, char *w2)
{
	char	*res;
	size_t	i;

	res = malloc(ft_strlen(w1) + ft_strlen(w2) + 2);
	//protect malloc
	i = 0;
	while (*w1)
		res[i++] = *w1++;
	res[i++] = ' ';
	while (*w2)
		res[i++] = *w2++;
	res[i] = '\0';
	return (res);
}

void	modify_cmd_string(t_token **token, t_node **cmd)
{
	char	*tmp;

	tmp = join_words((*cmd)->data.cmd.string, parse_word(token));
	consume(token);	
	free((*cmd)->data.cmd.string);
	(*cmd)->data.cmd.string = tmp;
}

bool	is_word_tk(t_token **token)
{
	if (!(*token))
		return (false);
	if ((*token)->class == WORD)
		return (true);
	return (false);
}
