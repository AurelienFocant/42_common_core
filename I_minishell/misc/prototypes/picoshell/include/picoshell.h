#ifndef PICOSHELL_H
# define PICOSHELL_H

#include "libft.h"
#include "parser.h"
#include "lexer.h"
#include "interpreter.h"


#include <stdio.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/ioctl.h>

#include <readline/readline.h>
#include <readline/history.h>

# define DEBUG_FLAG	01

typedef unsigned int t_exit_code;

typedef struct s_shell
{
	char		**envp;
	t_exit_code	last_exit_code;
	t_exit_code	current_exit_code;
	u_int8_t	flags;
}	t_shell;

#include "prototypes_picoshell.h"


#endif
