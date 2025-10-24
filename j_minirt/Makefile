#--------------------------PROGRAM NAME-----------------------#
NAME							:=	hugeRT
all:							$(NAME)

# ./$(NAME) worlds/world.rt

#-----------------------------HELP----------------------------#
help:
	@printf "	all:	make hugeRT\n"
	@printf "	leak:	run valgrind\n"
	@printf "	vgdb:	run valgrind with gbd\n"
	@printf "	tests:	run unit tests"

#---------------------------MAKE FLAGS------------------------#
MAKEFLAGS						:=	--no-print-directory
SHELL							:=	/bin/bash

#-----------------------------DEBUG---------------------------#
DEBUG_EXEC						:=	debugRT
debug:							$(DEBUG_EXEC)
	$(DB) $(DEBUG_EXEC)

OS = $(shell uname)
ifeq ($(OS),Darwin)
	DB = lldb
else
	DB = gdb
endif

#---------------------------COMPILER--------------------------#
CC								:=	cc
CFLAGS							:=	-Wall -Wextra -Werror
DEBUGFLAGS						:=	-g2
OPTIFLAGS						:=	-O3
# CFLAGS						+=	-fsanitize=address
# CFLAGS						+=	-fsanitize=undefined

LINK := $(shell ld -v 2>&1 | grep --quiet GNU && gold -v)
ifneq (,$(LINK))
	LDFLAGS			=	-fuse-ld=gold
endif

COMPILER						:=	$(CC) $(CFLAGS)
LINKER							:=	$(CC) $(CFLAGS) $(LDFLAGS)
ARCHIVER						:=	ar -rcs

#---------------------------LIBRARIES-------------------------#
#-----------------------------LIBFT---------------------------#
LIBS_DIR						:=	libs
LIBFT_DIR						:=	$(LIBS_DIR)/libft
LIBFT							:=	$(LIBFT_DIR)/libft.a
LIBFLAGS						:=	-L$(LIBFT_DIR) -lft

libft:	$(LIBFT)
$(LIBFT):
	@printf "LIBFT being created\n"
	@$(MAKE) -C $(LIBFT_DIR) all

#----------------------------MINILIBX-------------------------#
MINILIBX_LIB				:=	mlx
MINILIBX					:=	$(MINILIBX_DIR)/libmlx.a
ifeq ($(shell uname),Darwin)
	MINILIBX_DIR				:=	$(LIBS_DIR)/minilibx_opengl
 	LIBFLAGS   					+=	-framework OpenGL -framework AppKit
else
	MINILIBX_DIR				:=	$(LIBS_DIR)/minilibx_linux
	LIBFLAGS   					+=	-L/opt/X11/lib -lX11 -lXext
	CPPFLAGS					+=	-I/opt/X11/include/X11
endif
LIBFLAGS					+=	-L$(MINILIBX_DIR) -l$(MINILIBX_LIB)

minilibx:	$(MINILIBX)
$(MINILIBX):
	@printf "MINILIBX being created\n"
	@$(MAKE) -C $(MINILIBX_DIR) all &>/dev/null
	@printf "MINILIBX has been created\n"

#----------------------------LIBMATH--------------------------#
LIBFLAGS						+=	-lm

#-------------------------SOURCE FILES------------------------#
SRC_DIR							:=	src
SRC_SUBDIRS						:=	$(shell find $(SRC_DIR)/* -type d)
SRC_FILES						:=	$(shell find $(SRC_DIR) -type f -name "*.c")

#-------------------------OBJECT FILES------------------------#
OBJ_DIR							:=	.build
DEBUG_DIR						:=	$(OBJ_DIR)/debug_obj
OBJ_SUBDIRS						:=	$(SRC_SUBDIRS:$(SRC_DIR)%=$(OBJ_DIR)%)
OBJ_FILES						:=	$(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEBUG_OBJ						:=	$(SRC_FILES:$(SRC_DIR)%.c=$(DEBUG_DIR)%.o)


$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c | compiling
	@mkdir -p $(@D)
	$(COMPILER) $(OPTIFLAGS) $(CPPFLAGS) -c $< -o $@

$(DEBUG_DIR)/%.o:	$(SRC_DIR)/%.c | compiling
	@mkdir -p $(@D)
	$(COMPILER) $(DEBUGFLAGS) $(CPPFLAGS) -c $< -o $@

.INTERMEDIATE: compiling
compiling:
	@printf "\n-----------------COMPILING-----------------\n"

#--------------------------DEPENDENCIES-----------------------#
DEPS							:=	$(OBJ_FILES:.o=.d)
-include $(DEPS)
CPPFLAGS						:=	-MMD -MP

#--------------------------HEADER FILES-----------------------#
INC_DIR							:=	include
CPPFLAGS						+=	-I$(INC_DIR)
CPPFLAGS						+=	-I$(LIBFT_DIR)/$(INC_DIR)
CPPFLAGS						+=	-I$(MINILIBX_DIR) 


#----------------------------LINKING--------------------------#
$(NAME):		$(LIBFT) $(MINILIBX) $(OBJ_FILES) | linking
	$(LINKER) $(OPTIFLAGS) $(OBJ_FILES) $(LIBFLAGS) -o $@
	@printf "\n"

$(DEBUG_EXEC):	$(LIBFT) $(MINILIBX) $(DEBUG_OBJ) | linking
	$(LINKER) $(DEBUGFLAGS) $(DEBUG_OBJ) $(LIBFLAGS) -o $@
	@printf "\n"

.INTERMEDIATE: linking
linking:
	@printf "\n------------------LINKING------------------\n"

#----------------------------CLEANING-------------------------#
clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -rf	$(NAME)
	@rm -rf	$(DEBUG_EXEC)
	@printf	"$(NAME) fully cleaned\n"

re:		fclean all

libclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MINILIBX_DIR) clean &>/dev/null
	@printf "MINILIBX fully cleaned\n"

libre:		libclean libft minilibx

ffclean:	fclean libclean
fre:		ffclean re

.PHONY: all help \
	vgdb leak lsp \
	clean fclean re \
	libft minilibx libclean libre \
	ffclean fre \

#---------------------------DEBUGGING-------------------------#
vgdb: debug
	valgrind --vgdb-error=0 --vgdb=full --leak-check=full --show-leak-kinds=all ./debugRT worlds/invalid.rt -D WIDTH=80 -D HEIGHT=100

leak: all
	valgrind --leak-check=full --show-leak-kinds=all ./hugeRT worlds/invalid.rt

test: all
	@. unit_tests/tests.sh

lsp: fclean
	rm -rf ./misc/compile_commands.json
	rm -rf ./misc/.cache
	bear --output ./misc/compile_commands.json -- make

#-------------------------------------------------------------#
