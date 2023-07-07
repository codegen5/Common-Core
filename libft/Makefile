SRC			= ft_atoi ft_isalnum ft_isdigit ft_memcmp ft_memset	ft_strlcat ft_strncmp ft_tolower ft_bzero ft_isalpha ft_isprint ft_memcpy ft_strchr ft_strlcpy ft_strnstr ft_toupper ft_calloc ft_isascii ft_memchr ft_memmove ft_strdup ft_strlen ft_strrchr ft_substr ft_split

SRCS		= $(addsuffix .c, ${SRC})

HEAD		= ./includes/

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

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

all:		$(NAME)

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re:					fclean all

.PHONY:		all bonus clean fclean re
