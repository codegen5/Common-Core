NAME = push_swap
LIBDIR = libft/libft.a
CC = gcc

CFLAGS =  -Wall -Wextra -Werror

RM = rm -rf

SRCS = main.c check_error.c init.c free.c utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR) -o $(NAME)

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR):
	@make -C libft/
	@echo "compiled libft.a"

clean :
	$(RM) $(OBJS)
	@make clean -C libft/

fclean : clean
	$(RM) $(NAME)
	@make fclean -C libft/

re : fclean all

.PHONY : all clean fclean re