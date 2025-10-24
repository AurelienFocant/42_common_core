GCC			=	$(shell ls /opt/homebrew/Cellar/gcc/14.2.0_1/bin/g++-14 2>/dev/null)
ifneq ($(GCC),)
	CC			=	/opt/homebrew/Cellar/gcc/14.2.0_1/bin/g++-14
else
	CC			=	c++
endif

CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-std=c++98
DEBUGFLAGS	+=	-g -D_GLIBCXX_DEBUG


NAME		=	scavTrap
all: $(NAME)

# FIXEDCLASS	=	FixedClass
# CPPFLAGS	=	-I$(FIXEDCLASS)
# POINTCLASS	=	PointClass
# CPPFLAGS	+=	-I$(POINTCLASS)

SRC_FILES	=	$(shell find . -name "*.cpp")

OBJ_DIR		=	.build
OBJ_FILES	=	$(SRC_FILES:./%.cpp=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: ./%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEBUGFLAGS) -c $^ -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

re: clean all

lsp:
	@rm misc/compile_commands.json
	@bear --output misc/compile_commands.json -- make
