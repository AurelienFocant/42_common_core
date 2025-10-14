CC = gcc

CFLAGS = -Wall -Werror -Wextra

DFLAG = -g

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_print_nbr.c \
	  ft_print_ptr.c \
	  ft_printf_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(DFLAG) -c $^ -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf *.out*

re: fclean all

.PHONY = all clean fclean re
