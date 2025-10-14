
#include "picoshell.h"
#include "parser.h"
#include "lexer.h"
#include "interpreter.h"

t_token	*last_token(t_token *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back(t_token **token_list, t_token *new_token)
{
	if (*token_list)
		last_token(*token_list)->next = new_token;
	else
		*token_list = new_token;
	return;
}

void	print_linked_list(t_token *token_list)
{
	while (token_list)
	{
		print_token_class(token_list);
		token_list = token_list->next;
	}
}
