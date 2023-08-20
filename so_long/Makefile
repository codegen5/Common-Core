NAME		= so_long
#B_NAME		= 
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

SRC			= so_long.c
#B_SRC		=
OBJ			= $(SRC:.c=.o)
#B_OBJ		=

all: $(NAME)

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@echo "Linking $@"
	@$(CC) $(OBJ) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#$(B_NAME): %_bonus: %_bonus.o
#	@echo "Linking $@"
#	@$(CC) $(CFLAGS) $< -o $@

#bonus: $(B_NAME)

clean:
	@echo "Cleaning up..."
	@$(RM) $(OBJ)

fclean: clean
	@echo "Removing executables..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
