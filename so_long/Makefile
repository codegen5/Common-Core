NAME = so_long

B_NAME = so_long_bonus

SRCS = mandatory/controls.c mandatory/controls2.c mandatory/create_map.c mandatory/free.c mandatory/get_map.c mandatory/get_next_line.c \
mandatory/so_long_utils1.c mandatory/so_long_utils2.c mandatory/main.c mandatory/move.c mandatory/move1.c

B_SRCS = bonus/create_map_bonus.c bonus/main_bonus.c bonus/move_bonus.c bonus/controls_bonus.c bonus/controls2_bonus.c bonus/free_bonus.c \
bonus/get_map_bonus.c bonus/get_next_line_bonus.c bonus/so_long_utils1_bonus.c bonus/so_long_utils2_bonus.c bonus/move1_bonus.c

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

CC = gcc

MFLAGS = ./minilibx/libmlx.a

AFLAGS =  -Wall -Wextra -Werror

RM = rm -rf

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./minilibx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

$(B_NAME): $(B_OBJS)
	$(CC) $(B_OBJS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(B_NAME)

fclean : clean
	rm -rf $(NAME) $(B_NAME)

clean :
	make clean -C ./minilibx
	rm -rf $(OBJS) $(B_OBJS)

re : fclean all

bonus : $(MFLAGS) $(B_NAME)

.PHONY : all fclean clean re bonus