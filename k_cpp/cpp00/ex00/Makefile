#--------------------------PROGRAM NAME-----------------------#
NAME							:=	megaphone
all:							$(NAME)

MAKEFLAGS						:=	--no-print-directory
SHELL							:=	/bin/bash


#---------------------------COMPILER--------------------------#
CC								:=	c++
CFLAGS							:=	-Wall -Wextra -Werror
CFLAGS							+=	-std=c++98
CFLAGS							+=	-g2

LINK := $(shell ld -v 2>&1 | grep --quiet GNU && gold -v)
ifneq (,$(LINK))
	LDFLAGS			=	-fuse-ld=gold
endif

COMPILER						:=	$(CC) $(CFLAGS)
LINKER							:=	$(CC) $(CFLAGS) $(LDFLAGS)
ARCHIVER						:=	ar -rcs

#-------------------------SOURCE FILES------------------------#
SRC_DIR							:=	.
SRC_FILES						:=	$(shell find $(SRC_DIR) -type f -name "*.cpp")

#-------------------------OBJECT FILES------------------------#
OBJ_DIR							:=	.build
OBJ_FILES						:=	$(SRC_FILES:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)


$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp | compiling
	@mkdir -p $(@D)
	$(COMPILER) $(CPPFLAGS) -c $< -o $@

.INTERMEDIATE: compiling
compiling:
	@printf "\n-----------------COMPILING-----------------\n"


#--------------------------DEPENDENCIES-----------------------#
DEPS							:=	$(OBJ_FILES:.o=.d)
-include $(DEPS)
CPPFLAGS						:=	-MMD -MP

#--------------------------HEADER FILES-----------------------#
INC_DIR							:=	include

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

.PHONY: all \
		vgdb leak lsp \
		clean fclean re \

#---------------------------DEBUGGING-------------------------#
vgdb: all
	valgrind --vgdb-error=0 --vgdb=full --leak-check=full --show-leak-kinds=all ./$(NAME)

lsp: fclean
	rm -rf ./misc/compile_commands.json
	rm -rf ./misc/.cache
	bear --output ./misc/compile_commands.json -- make

#-------------------------------------------------------------#
