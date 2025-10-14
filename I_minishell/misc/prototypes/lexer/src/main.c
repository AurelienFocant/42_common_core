/* ************************************************************************** */
/*                                                                            */
/*   main.c                                               :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By:  afocant  <afocant@student.s19.be>           +:+ +:+         +:+     */
/*   And: slangero <slangero@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:30:23 by afocant           #+#    #+#             */
/*   Updated: 2025/01/10 14:30:29 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*build_token(t_tk_class class, char *lexeme)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->class = class;
	token->lexeme = lexeme;
	token->next = NULL;
	return (token);
}

t_token	*lexer(char *input)
{
	t_token	*token_list;
	t_token	*token;
	char	*current;

	token_list = NULL;
	current = input;
	while (*current)
	{
		while (is_whitespace(*current))
			current++;
		if (is_single_operator(*current))
			token = tokenise_single_operator(&current);
		else if (is_double_operator(*current))
			token = tokenise_double_operator(&current);
		else if (is_word(*current))
			token = tokenise_word(&current);
		else
		{
			printf("wrong char\n");
			exit(EXIT_FAILURE);
		}
		add_back(&token_list, token);
		current++;
	}
	return (token_list);
}

int	main(int ac, char **av)
{
	t_token	*tokens;

	if (ac != 2)
	{
		printf("Usage args\n");
		exit(1);
	}
	tokens = lexer(av[1]);
	print_linked_list(tokens);
}	
