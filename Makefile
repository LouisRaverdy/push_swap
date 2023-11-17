LIBC =	ft_printf.c ft_printf_utils.c ft_print_ptr.c

SRCS = ${LIBC} ${ADDITIONAL} ${EXTRA}

SRCSALL = ${LIBC} ${ADDITIONAL} ${BONUS} ${EXTRA}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o}

LIBFT = libft

NAME = libftprintf.a

CC = gcc

CFLAGS += -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@make -C $(LIBFT)
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		ar -rsc ${NAME} ${OBJS}

all:	${NAME}

clean:
		rm -f ${OBJSALL}

fclean:	clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus
