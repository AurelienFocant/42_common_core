CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

HDR = includes

LIB = libft.a

OBJ = $(SRC:%.c=%.o)

.PHONY: all clean fclean re

all: $(LIB)

$(LIB): $(OBJ)
	ar -rc $@ $^

$(OBJ):
	$(CC) $(CFLAGS) -I $(HDR) -c $(@:.o=.c) -o $@

clean:
	rm $(OBJ)

fclean: clean
	rm $(LIB)

re: fclean all
