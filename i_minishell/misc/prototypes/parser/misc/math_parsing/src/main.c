#include "math_parsing.h"

int	main(int ac, char **argv)
{
	t_token		*tokens;
	tree_node	*node;
	(void)argv;

	t_token	tk1;
	t_token	tk2;
	t_token	tk3;
	t_token	tk4;
	t_token	tk5;
	t_token	tk6;
	t_token	tk7;

	/*tk1.lexeme = "(";*/
	/*tk1.next = &tk2;*/
	tk2.lexeme = "3";
	tk2.next = &tk3;
	tk3.lexeme = "+";
	tk3.next = &tk4;
	tk4.lexeme = "5";
	tk4.next = &tk6;
	/*tk5.lexeme = ")";*/
	/*tk5.next = &tk6;*/
	tk6.lexeme = "+";
	tk6.next = &tk7;;
	tk7.lexeme = "2";
	tk7.next = NULL;

	tokens = &tk2;
	// tokens = lexer(argv[1]);
	node = parseE(&tokens);
	(void) node;
	return (0);
}

