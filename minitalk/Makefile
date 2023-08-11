NAME		= client server
B_NAME		= client_bonus server_bonus
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

SRCS		= client.c server.c
B_SRCS		= client_bonus.c server_bonus.c
OBJS		= $(SRCS:.c=.o)
B_OBJS		= $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): %: %.o
	@echo "Linking $@"
	@$(CC) $(CFLAGS) $< -o $@ 

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(B_NAME): %_bonus: %_bonus.o
	@echo "Linking $@"
	@$(CC) $(CFLAGS) $< -o $@

bonus: $(B_NAME)

clean:
	@echo "Cleaning up..."
	@$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	@echo "Removing executables..."
	@$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
