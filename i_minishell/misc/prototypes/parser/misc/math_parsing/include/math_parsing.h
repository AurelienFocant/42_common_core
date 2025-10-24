#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "libft.h"
#include "math_parsing.h"

#define INT_TK	0
#define OP_TK	1

typedef struct s_token
{
	int				class;
	char			*lexeme;
	struct s_token	*next;
}	t_token;

typedef struct s_node
{
	int				type;
	char			*value;
	struct s_node	*left;
	struct s_node	*right;
}	tree_node;

#include "prototypes_math_parsing.h"

#endif
