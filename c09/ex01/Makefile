CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = includes
SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_strlen.c srcs/ft_putstr.c srcs/ft_strcmp.c
NAME = libft.a
OBJECTS = $(SRC:.c=.o)
all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I $(HEAD)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
