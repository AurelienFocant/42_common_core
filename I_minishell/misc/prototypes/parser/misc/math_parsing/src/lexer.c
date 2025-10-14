#include "math_parsing.h"
#include "libft.h"

size_t	ft_toklen(char *s, char *e)
{
	size_t	i;

	i = 0;
	while (s != e)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_tokenise(char *s, char *e)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_toklen(s, e);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s != e)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

bool	ft_add_back(t_token **tokens, t_token *node)
{
	t_token	*ptr;

	if (!*tokens)
	{
		*tokens = node;
		return (true);
	}
	ptr = *tokens;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = node;
	return (true);
}

bool	build_int_node(t_token **tokens, char *s, char *e)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (false);
	node->class = INT_TK;
	node->lexeme = (void *) ft_tokenise(s, e);
	node->next = NULL;
	ft_add_back(tokens, node);
	return (true);
}

bool	build_op_node(t_token **tokens, char *s, char *e)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (false);
	node->class = OP_TK;
	node->lexeme = (void *) ft_tokenise(s, e);
	node->next = NULL;
	ft_add_back(tokens, node);
	return (true);
}

t_token	*lexer(char *input)
{
	t_token	*tokens;
	char	*e;
	char	*s;

	tokens = NULL;
	s = input;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (ft_isdigit(*s))
		{
			e = s;
			while (ft_isdigit(*e))
				e++;
			build_int_node(&tokens, s, e);
			s = e;
		}
		while (ft_isspace(*s))
			s++;
		if (*s == '+' || *s == '*')
		{
			build_op_node(&tokens, s, s + 1);
			s++;	
		}
	}
	return (tokens);
}
