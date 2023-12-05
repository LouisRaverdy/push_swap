NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I include
RM = rm -f

SRCS = operations/push.c operations/reverse_rotate.c operations/rotate.c \
operations/swap.c cost.c position.c push_swap_utils_bis.c max_move.c\
push_swap_utils.c tiny_sort.c sort.c libft_utils.c push_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
