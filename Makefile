NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I include
BONUS_CFLAGS = -Wall -Werror -Wextra -I bonus/include
RM = rm -f

SRCS = operations/push.c operations/reverse_rotate.c operations/rotate.c \
operations/swap.c cost.c position.c push_swap_utils_bis.c max_move.c\
push_swap_utils.c tiny_sort.c sort.c libft_utils.c push_swap.c ft_split.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = operations/push.c operations/reverse_rotate.c operations/rotate.c \
operations/swap.c cost.c position.c push_swap_utils_bis.c max_move.c\
push_swap_utils.c tiny_sort.c sort.c libft_utils.c bonus/checker.c ft_split.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
