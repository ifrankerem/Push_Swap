NAME = push_swap

SRCS = error.c main.c moves.c moves2.c stack_utils.c utils.c parsing.c pushswapp.c split.c turkishalgo.c
OBJS = error.o main.o moves.o moves2.o stack_utils.o utils.o parsing.o pushswapp.o split.o turkishalgo.o

LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft -s
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft -s
	rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft -s
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
