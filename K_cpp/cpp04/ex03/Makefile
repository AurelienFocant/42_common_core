GCC			:=	$(shell ls /opt/homebrew/Cellar/gcc/14.2.0_1/bin/g++-14 2>/dev/null)
ifneq ($(GCC),)
	CC			:=	/opt/homebrew/Cellar/gcc/14.2.0_1/bin/g++-14
else
	CC			:=	g++
endif

CFLAGS		=	-std=c++98
CFLAGS		+=	-Wall -Wextra -Werror
DEBUGFLAGS	=	-g -D_GLIBCXX_DEBUG
DEBUGFLAGS	+=	-fdump-lang-class


NAME		=	penultimateFantasy

all: $(NAME)

SRC_FILES	=	$(shell find . -name "*.cpp")

OBJ_DIR		=	.build
OBJ_FILES	=	$(SRC_FILES:./%.cpp=$(OBJ_DIR)/%.o)

#--------------------------DEPENDENCIES-----------------------#
DEPS							:=	$(OBJ_FILES:.o=.d)
-include $(DEPS)
CPPFLAGS						:=	-MMD -MP

CPPFLAGS						+= $(addprefix -I, $(shell find Classes -type d))


$(OBJ_DIR)/%.o: ./%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

re: clean all

lsp: clean
	@rm -f misc/compile_commands.json
	@bear --output misc/compile_commands.json -- make
