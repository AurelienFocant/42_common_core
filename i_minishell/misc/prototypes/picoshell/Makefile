#-------------------------PROGRAM NAME------------------------#
NAME							:=	picoshell
all:							$(NAME)

MAKEFLAGS						:=	--no-print-directory

#---------------------------COMPILER--------------------------#
CC								:=	cc
CFLAGS							:=	-Wall -Wextra -Werror
CFLAGS							+=	-g3

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

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(COMPILER) $(CPPFLAGS) -c $< -o $@

#-----------------------------LIBFT---------------------------#
LIBFT_DIR						:=	libft
LIBFT							:=	$(LIBFT_DIR)/libft.a
LIBFLAGS						:=	-L$(LIBFT_DIR) -lft

libft:	$(LIBFT)
$(LIBFT):
	@echo "LIBFT being created"
	@$(MAKE) -C $(LIBFT_DIR) all

#----------------------------READLINE-------------------------#
BREW_PREFIX := $(shell 2>/dev/null brew --prefix)
ifneq (,$(BREW_PREFIX))
	BREW_DIR 					:=	$(wildcard $(BREW_PREFIX)/Cellar/readline/8.2.13)
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
$(NAME):	$(LIBFT) $(OBJ_FILES)
	$(LINKER) $(OBJ_FILES) $(LIBFLAGS) -o $@

#----------------------------CLEANING-------------------------#
clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -rf $(NAME)
	@echo  "$(NAME) fully cleaned"

re:		fclean all

libclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
libre:		libclean libft

ffclean:	fclean libclean
fre:		ffclean re

.PHONY: all libft clean fclean re libclean libre ffclean fre
#-------------------------------------------------------------#
