#ifndef INTERPRETER_H
# define INTERPRETER_H

#include <stdbool.h>

# define NO_FILE	(-1)
# define CHILD		0

#include "parser.h"


typedef struct s_ctxt
{
	int	input;
	int	output;
	int	to_close;
}	t_ctxt;



#endif
