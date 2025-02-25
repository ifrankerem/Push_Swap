NAME = push_swap

SRCS = error.c main.c moves.c moves2.c stack_utils.c utils.c parsing.c pushswapp.c split.c turkishalgo.c

LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(SRCS)
	@make -C ./libft -s
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C ./libft -s

fclean: clean
	@make fclean -C ./libft -s
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
