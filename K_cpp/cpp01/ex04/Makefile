GCC			=	$(shell ls /opt/homebrew/Cellar/gcc/14.2.0_1/bin/g++-14 2>/dev/null)
ifneq ($(GCC),)
	CC			=	/opt/homebrew/Cellar/gcc/14.2.0_1/bin/g++-14
else
	CC			=	c++
endif

CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-std=c++98
CFLAGS		+=	-ggdb3 -save-temps=obj

NAME		=	sed_is_for_losers
all: $(NAME)

SRC_FILES	=	$(shell find . -name "*.cpp")

OBJ_DIR		=	.build
OBJ_FILES	=	$(SRC_FILES:./%.cpp=$(OBJ_DIR)/%.o)

DEPS							:=	$(OBJ_FILES:.o=.d)
-include $(DEPS)
CPPFLAGS						:=	-MMD -MP

$(OBJ_DIR)/%.o: ./%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

re: clean all

lsp: clean
	bear --output misc/compile_commands.json -- make
