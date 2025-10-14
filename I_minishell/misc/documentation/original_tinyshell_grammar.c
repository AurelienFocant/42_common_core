program             :   command_line
                    ;

command_line        :   pipeline '&&' command_line
                    |   pipeline '||' command_line
                    |   pipeline
                    ;

pipeline            :   command '|' pipeline
                    |   command
                    ;

command             :   subshell
                    |   simple_command
                    ;

subshell            :   '(' command_line ')' io_redirect
					|   '(' command_line ')'
                    ;

simple_command      :   cmd_prefix CMD_NAME cmd_suffix   //this word is the cmd_name
                    |   cmd_prefix CMD_NAME
                    |   cmd_prefix
                    |   CMD_NAME cmd_suffix
                    |   CMD_NAME
                    ;

cmd_name            :   WORD
                    ;

cmd_prefix          :               io_redirect
                    |   cmd_prefix  io_redirect
                    ;

cmd_suffix          :               io_redirect
                    |   cmd_suffix  io_redirect
                    |               OPTION_NAME
                    |   cmd_suffix  OPTION_NAME
                    ;

option_name         :   WORD
                    ;

io_redirect         :   io_file
                    |   io_here
                    ;

io_file             :   '<'     FILENAME
                    |   '>'     FILENAME
                    |   '>>'    FILENAME
                    ;

io_here             :   '<<' WORD
                    ;

filename            :   WORD
                    ;
