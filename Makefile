NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I include -I bonus/include
RM = rm -f

REQUIRED_SRCS = operations/push.c operations/reverse_rotate.c operations/rotate.c \
operations/swap.c cost.c position.c push_swap_utils_bis.c max_move.c\
push_swap_utils.c tiny_sort.c sort.c libft_utils.c ft_split.c

NORMAL_SRCS = $(REQUIRED_SRCS) push_swap.c

NORMAL_OBJS = $(NORMAL_SRCS:.c=.o)

BONUS_SRCS = $(REQUIRED_SRCS) bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/libft_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(NORMAL_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(NORMAL_OBJS)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

clean:
	$(RM) $(NORMAL_OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
