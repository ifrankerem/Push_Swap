NAME = push_swap

SRCS = error.c main.c pushmoves.c reverserotatemoves.c rotatemoves.c swapmoves.c stack_utils.c utils.c parsing.c pushswapp.c algo.c stack_utils2.c algo2.c

LIBFT		= libft/libft.a
DIR_LIBFT	= libft
CC = cc
CFLAGS =  -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./libft -s
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	make clean -C ./libft -s

fclean: clean
	make fclean -C ./libft -s
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
