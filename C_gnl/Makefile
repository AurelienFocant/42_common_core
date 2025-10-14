#CC= /opt/homebrew/opt/llvm/bin/clang-18
CC = cc

CFLAGS = -Wall -Werror -Wextra

DEBUG = -fsanitize=address -fsanitize=undefined

SRC = get_next_line.c \
	  get_next_line_utils.c \

OBJ = $(SRC:.c=.o)
	
NAME = a.out

BONUS_SRC = get_next_line_bonus.c \
			get_next_line_utils_bonus.c \

BONUS_OBJ = $(BONUS_SRC:.c=.o)

BONUS_NAME = a.bonus

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ) main.c
	$(CC) $(STACK) $(CFLAGS) $(DEBUG) -g $^ -o $@

$(BONUS_NAME): $(BONUS_OBJ) main.c
	$(CC) $(STACK) $(CFLAGS) $(DEBUG) -g $^ -o $@

%.o: %.c
	$(CC) $(STACK) $(CFLAGS) $(DEBUG) -g -c $^ -o $@

clean:
	rm -rf $(BONUS_OBJ) $(OBJ)

fclean: clean
	rm -rf $(BONUS_NAME) $(NAME) *dSYM

re: fclean all
