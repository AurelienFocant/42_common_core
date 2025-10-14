#-----------------------COMPILER------------------------------#
CC							=	cc
CFLAGS			    		=	-Wall -Wextra -Werror
GFLAGS			    		=	-g3
MAKEFLAGS		    		=	--no-print-directory

LINK	=   $(shell ld -v 2>&1 | grep GNU && lld -v)
ifneq ($(LINK),)
	LDFLAGS	    =	-fuse-ld=lld
endif

COMPILER					=	$(CC) $(CFLAGS) $(GFLAGS)
LINKER						=	$(CC) $(LDFLAGS) $(CFLAGS) $(GFLAGS)
ARCHIVER					=	ar -rcs

#-----------------------HEADER FILES--------------------------#
INC_DIR						=	include
INC_FLAGS					=	-I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)

#-----------------------SOURCE FILES--------------------------#
SRC_DIR						=	src
OBJ_DIR						=	obj
SRC_SUBDIRS					=	$(shell find $(SRC_DIR)/* -type d)
OBJ_SUBDIRS					=	$(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC_SUBDIRS))

PUSH_SRC					=	$(SRC_DIR)/push_swap_main.c
CHECK_SRC					=	$(SRC_DIR)/checker_main_bonus.c
PUSH_OBJ					=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(PUSH_SRC))
CHECK_OBJ					=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CHECK_SRC))

#-----------------------PUSH_SWAP LIB-------------------------#
PUSH_LIB_SRC				=	$(shell find $(SRC_DIR) -type f -name "*.c" | grep -v main)
PUSH_LIB_OBJ				=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(PUSH_LIB_SRC))
#$(info PS LIB OBJ : $(PUSH_LIB_OBJ))
PUSH_LIB					=	$(OBJ_DIR)/libpush.a
PUSH_FLAGS					=	-L$(OBJ_DIR) -lpush

#-------------------------LIBFT-------------------------------#
LIBFT_DIR					=	libft
LIBFT						=	$(LIBFT_DIR)/libft.a
FT							=	ft
LIBFT_FLAGS					=	-L$(LIBFT_DIR) -l$(FT)

#-----------------------MAKE RULES----------------------------#
NAME						=	push_swap
CHECKER						=	checker

all:						$(NAME)
pslib:						$(PUSH_LIB)
libft:						$(LIBFT)
bonus:						$(CHECKER)

$(NAME):					$(LIBFT) $(PUSH_LIB) $(PUSH_OBJ)
	$(LINKER) $(PUSH_OBJ) $(PUSH_FLAGS) $(LIBFT_FLAGS) -o $@

$(CHECKER):					$(LIBFT) $(PUSH_LIB) $(CHECK_OBJ)
	$(LINKER) $(CHECK_OBJ) $(PUSH_FLAGS) $(LIBFT_FLAGS) -o $@

$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(COMPILER) $(INC_FLAGS) -c $< -o $@

$(PUSH_LIB):				$(PUSH_LIB_OBJ)
	$(ARCHIVER) $@ $(PUSH_LIB_OBJ)

$(LIBFT):
	@echo "LIBFT being created"
	@$(MAKE) -C $(LIBFT_DIR) all
#-----------------------CLEAN RULES---------------------------#
clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -rf $(NAME)
	@rm -rf $(CHECKER)
	@echo "Push Swap fully cleaned"

libclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean

libre: libclean libft

re: fclean all

ffclean: fclean libclean

.PHONY: all lib clean fclean libclean libre re ffclean bonus
#-------------------------------------------------------------#
