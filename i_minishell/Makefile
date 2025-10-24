#--------------------------PROGRAM NAME-----------------------#
NAME							:=	tinyshell
all:							$(NAME)

MAKEFLAGS						:=	--no-print-directory
SHELL							:=	/bin/bash

#-----------------------------HELP----------------------------#
help:
	@printf "	all:	make tinyshell\n"
	@printf "	ast:	build ast if --ast or --debug option is set\n"
	@printf "	vgdb:	run valgrind with gbd\n"
	@printf "	leak:	run valgrind in interactive mode\n"
	@printf "	leaks:	run valgrind in command mode\n"
	@printf "	tests:	run unit tests"

#---------------------------COMPILER--------------------------#
CC								:=	cc
CFLAGS							:=	-Wall -Wextra -Werror
CFLAGS							+=	-g2

# CFLAGS							+=	-fsanitize=address
# CFLAGS							+=	-fsanitize=undefined

LINK := $(shell ld -v 2>&1 | grep --quiet GNU && gold -v)
ifneq (,$(LINK))
	LDFLAGS			=	-fuse-ld=gold
endif

COMPILER						:=	$(CC) $(CFLAGS)
LINKER							:=	$(CC) $(CFLAGS) $(LDFLAGS)
ARCHIVER						:=	ar -rcs

#-------------------------SOURCE FILES------------------------#
SRC_DIR							:=	src
SRC_SUBDIRS						:=	$(shell find $(SRC_DIR)/* -type d)
SRC_FILES						:=	$(shell find $(SRC_DIR) -type f -name "*.c")

#-------------------------OBJECT FILES------------------------#
OBJ_DIR							:=	.build
OBJ_SUBDIRS						:=	$(SRC_SUBDIRS:$(SRC_DIR)%=$(OBJ_DIR)%)
OBJ_FILES						:=	$(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | compiling
	@mkdir -p $(@D)
	$(COMPILER) $(CPPFLAGS) -c $< -o $@

.INTERMEDIATE: compiling
compiling:
	@printf "\n-----------------COMPILING-----------------\n"

#-----------------------------LIBFT---------------------------#
LIBFT_DIR						:=	libft
LIBFT							:=	$(LIBFT_DIR)/libft.a
LIBFLAGS						:=	-L$(LIBFT_DIR) -lft

libft:	$(LIBFT)
$(LIBFT):
	@printf "LIBFT being created\n"
	@$(MAKE) -C $(LIBFT_DIR) all

#----------------------------READLINE-------------------------#
BREW_PREFIX := $(shell 2>/dev/null brew --prefix)
ifneq (,$(BREW_PREFIX))
	BREW_DIR 					:=	$(wildcard $(BREW_PREFIX)/Cellar/readline/8.3.1)
endif
ifneq (,$(BREW_DIR))
	READLINE_DIR				:=	$(BREW_DIR)/lib
	READLINE_HEADER				:=	$(BREW_DIR)/include
else
	READLINE_DIR				:=	/usr/lib/x86_64-linux-gnu/
	READLINE_HEADER				:=	/usr/include
endif
LIBFLAGS						+=	-L$(READLINE_DIR) -lreadline

#--------------------------DEPENDENCIES-----------------------#
DEPS							:=	$(OBJ_FILES:.o=.d)
-include $(DEPS)
CPPFLAGS						:=	-MMD -MP

#--------------------------HEADER FILES-----------------------#
INC_DIR							:=	include
CPPFLAGS						+=	-I$(INC_DIR)
CPPFLAGS						+=	-I$(LIBFT_DIR)/$(INC_DIR)
CPPFLAGS						+=	-I$(READLINE_HEADER)

#----------------------------LINKING--------------------------#
$(NAME):	$(LIBFT) $(OBJ_FILES) | linking
	$(LINKER) $(OBJ_FILES) $(LIBFLAGS) -o $@

.INTERMEDIATE: linking
linking:
	@printf "\n------------------LINKING------------------\n"

#----------------------------CLEANING-------------------------#
clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -rf	$(NAME)
	@printf	"$(NAME) fully cleaned\n"

re:		fclean all

libclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean

libre:		libclean libft

ffclean:	fclean libclean
fre:		ffclean re

.PHONY: all help \
		ast vgdb leak leaks lsp \
		clean fclean re \
		libft libclean libre \
		ffclean fre \

#---------------------------DEBUGGING-------------------------#
ast:
	@./misc/graph/dot_to_graph.sh

vgdb: all
	valgrind --suppressions=./misc/readline.supp --vgdb-error=0 --vgdb=full --leak-check=full --show-leak-kinds=all ./tinyshell

leak: all
	valgrind --suppressions=./misc/readline.supp --track-origins=yes --track-fds=yes --trace-children=no --leak-check=full --show-leak-kinds=all ./tinyshell --ast

leaks: all
	@while true;\
	do \
		printf "\n"; \
		read -p "tinyleak: " line; \
		printf 'valgrind --leak-check=full --show-leak-kinds=all ./tinyshell --ast -c "$$line"\n' ;\
		valgrind --suppressions=./misc/readline.supp --track-origins=yes --track-fds=yes --leak-check=full --show-leak-kinds=all ./tinyshell --ast -c "$$line" ;\
	done ;

lsp: fclean
	rm -rf ./misc/compile_commands.json
	rm -rf ./misc/.cache
	bear --output ./misc/compile_commands.json -- make

test: all
	@chmod 755 ./unit_tester/run_test.sh
	@./unit_tester/run_test.sh
test1: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 1
test2: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 2
test3: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 3
test4: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 4
test5: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 5
test6: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 6
test7: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 7
test8: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 8
test9: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 9
test10: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 10
test11: all
	@python3 ./unit_tester/pexpect_unit_test.py -v 11

#-------------------------------------------------------------#
