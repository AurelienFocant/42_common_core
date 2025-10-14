// terminals : '+', '-', '*', '/', '(', ')', int
// non-terminals: E, F, T
// ========================= //
// E	: T + E
//	 	| T - E
//		| T
//		;
// T	: F * T
//		: F / T
//		| F
//		;
// F	: '(' E ')'
//		| int
//		;
// ========================= //
// E	: T ( '+'|'-' T )*
//		;
// T	: F { '*'|'/' F }*
//		;
// F	: '(' E ')'
//		| int
//		;
// ========================= //
// node-types: 
//
// number_nodes, add_nodes, sub_nodes, mult_nodes, div_nodes;
// number_nodes, binary_op_nodes;
// ========================= //

#include <stdlib.h>
#include <stdio.h>

#include "math_parsing.h"

# define ADD	0
# define MULT	1
# define INT	2


// --------------UTILS ---------------
void	consume(t_token **token)
{ 
	*token = (*token)->next;
}

int		is_paren(t_token *token)
{
	if (!ft_strcmp(token->lexeme, ")"))
			return (1);
	if (!ft_strcmp(token->lexeme, "("))
			return (1);
	return (0);
}

char	next_token(t_token *token)
{
	if (!token->next)
		return 0;
	if (!ft_strcmp(token->next->lexeme, "+"))
			return ('+');
	if (!ft_strcmp(token->next->lexeme, "*"))
			return ('*');
	if (!ft_strcmp(token->next->lexeme, ")"))
			return (')');
	return 0;
}


// ------------NODE BUILDING --------
tree_node	*buildNumber(t_token *token)
{ 
	tree_node	*node;

	node = malloc(sizeof(tree_node));
	node->type = INT;
	node->value = token->lexeme;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

tree_node	*buildMultiplication(tree_node *left, tree_node *right)
{
	tree_node	*node;

	node = malloc(sizeof(tree_node));
	node->type = MULT;
	node->value = "M";
	node->left = left;
	node->right = right;
	return (node);
}

tree_node	*buildAddition(tree_node *left, tree_node *right)
{
	tree_node	*node;

	node = malloc(sizeof(tree_node));
	node->type = ADD;
	node->value = "A";
	node->left = left;
	node->right = right;
	return (node);
}


// ------------GRAMMAR RULES ---------
tree_node	*parseF(t_token **token)
{ 
	tree_node	*node;

	if (is_paren(*token))
	{
		consume(token);
		node = parseE(token);
		if (next_token(*token) != ')')
			printf("ERROR CLOSING PARENTHESIS\n");
		consume(token);
	}
	else
		node = buildNumber(*token);
	return (node);
}

tree_node	*parseT(t_token **token)
{ 
	tree_node	*left;
	tree_node	*right;
	tree_node	*node;

	left = parseF(token);
	if (next_token(*token) == '*')
	{
		consume(token);
		consume(token);
		right = parseT(token);
		node = buildMultiplication(left, right);
		return (node);
	}
	return (left);
}

tree_node	*parseE(t_token **token)
{
	tree_node	*node;
	tree_node	*left;
	tree_node	*right;

	left = parseT(token);
	if (next_token(*token) == '+')
	{
		consume(token);
		consume(token);
		right = parseE(token);
		node = buildAddition(left, right);
		return (node);
	}
	return (left);
}
