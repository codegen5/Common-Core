SRCS			= ft_printf.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC					= gcc

RM					= rm -f

AR					= ar rc

RN					= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
					${AR} ${NAME} ${OBJS}
					${RN} ${NAME}

all:		${NAME} 

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re:					fclean all

.PHONY:		all clean fclean re
