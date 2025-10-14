CC			=	g++
CFLAGS		=	-std=c++98
CFLAGS		+=	-Wall -Wextra -Werror

NAME		=	bankAccount

all: $(NAME)

SRC_FILES	=	$(shell find . -name "*.cpp")

OBJ_DIR		=	.build
OBJ_FILES	=	$(SRC_FILES:./%.cpp=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: ./%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -g $(CFLAGS) $^ -o $@

$(NAME): $(OBJ_FILES)
	$(CC) -g $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

re: clean all

lsp:
	@bear --output misc/compile_commands.json -- make
