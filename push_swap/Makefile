NAME = push_swap

SRCS = main.c check_error.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS =  -Wall -Wextra -Werror

RM = rm -rf

all : $(NAME)

$(NAME): $(SRCS) $(LIBDIR)
	$(CC) $(SRCS) $(LIBDIR) -o $(NAME) $(CFLAGS)

$(LIBDIR):
	@make -C libft/
	@echo "compiled libft.a\n"

clean :
	$(RM) $(OBJS) $(B_OBJS)
	@make clean -C libft/

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re