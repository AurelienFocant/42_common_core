command_line        :   conditional_line
                    ;

conditional_line    :   pipeline ('&&'|'||' pipeline)*
                    ;

pipeline            :   subshell ('|' subshell)*
                    ;

subshell            :   '(' command_line ')' (io_redirect)*
                    |   command
                    ;

command             :   (cmd_prefix)* (CMD_NAME)? (cmd_suffix)*   //this word is the cmd_name
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

cmd_suffix          :	(OPTION_NAME|io_redirect)*
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
