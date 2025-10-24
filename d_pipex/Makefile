#---------------------------------------------------------#
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
GFLAGS			=	-g3
LNK				=	$(shell ld -v 2>&1 | grep --quiet GNU && which lld >/dev/null && echo lld)
ifeq ($(LNK), lld)
	LNKFLAGS	=	-fuse-ld=lld
endif

MAKEFLAGS		=	--no-print-directory

COMPILER		=	$(CC) $(CFLAGS) $(GFLAGS)
LINKER			=	$(CC) $(LNKFLAGS) $(CFLAGS) $(GFLAGS)
#---------------------------------------------------------#
SRC_DIR			=	src
SRC				=	$(shell find src -type f)

OBJ_DIR			=	obj
OBJ				=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
#---------------------------------------------------------#
INC_DIR			=	include
INC_FLAGS		=	-I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)

LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a
FT				=	ft
LIB_FLAGS		=	-L$(LIBFT_DIR) -l$(FT)
#---------------------------------------------------------#
NAME			=	pipex
all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJ)
	$(LINKER) $(OBJ) $(LIB_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(COMPILER) $(INC_FLAGS) -c $< -o $@ 

lib:			$(LIBFT)
$(LIBFT):
	@echo "LIBFT being created"
	@$(MAKE) -C $(LIBFT_DIR)
#---------------------------------------------------------#
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)

fclean:		clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

libclean:
	rm -rf $(LIBFT_DIR)/$(OBJ_DIR)
	rm -rf $(LIBFT)

ffclean: fclean libclean

re: fclean lib all

libre: libclean lib

.PHONY: all lib libre clean fclean libclean ffclean re
#---------------------------------------------------------#
