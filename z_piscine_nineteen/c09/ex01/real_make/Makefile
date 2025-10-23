CC = cc

CFLAGS = -Wall -Wextra -Werror

EXEC = app

LIB = libft.a

SRC_DIR = ./srcs

OBJ_DIR = ./objs

HDRS_DIR = ./includes

INCL = ft.h

SRCS = $(wildcard $(SRC_DIR)/*.c)

HDRS = $(wildcard $(HDRS_DIR/*.h) 

OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# these are complete synonyms
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
#
#
#
#
all: $(EXEC)

libft: $(LIB)
#
#
#
#
$(EXEC): $(LIB) 
	$(CC) $(CFLAGS) main.c $(LIB) -I$(HDRS_DIR) -o $@

$(LIB): $(OBJ)
	ar -rcs $@ $^ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(HDRS_DIR) -c $< -o $@
#
#
#
#
clean:
	rm $(OBJ)

fclean: clean
	rm $(LIB) $(EXEC)

re: fclean all
